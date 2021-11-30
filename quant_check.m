clc;
close all;
clear all;
net = importKerasNetwork('0-9-A-Z_selva.h5');
%analyzeNetwork(net)
%Input Layer Details
n_L=net.Layers(1,1).InputSize;
%Convolution Layer1 Details
n_C1=net.Layers(2,1).NumChannels;
f1=net.Layers(2,1).FilterSize;
S1=net.Layers(2,1).Stride;
padmode1=net.Layers(2,1).PaddingMode;
pad1=net.Layers(2,1).PaddingSize;
W1=net.Layers(2,1).Weights;
b1=net.Layers(2,1).Bias;
%Convolution Layer2 Details
n_C2=net.Layers(5,1).NumChannels;
f2=net.Layers(5,1).FilterSize;
S2=net.Layers(5,1).Stride;
padmode2=net.Layers(5,1).PaddingMode;
pad2=net.Layers(5,1).PaddingSize;
W2=net.Layers(5,1).Weights;
b2=net.Layers(5,1).Bias;
%Extract Theta1 from the net
wf1=net.Layers(10,1).Weights;
bf1=net.Layers(10,1).Bias;
%%inference
arr=['102.png'; '146.png'; '149.png'; '150.png'; '157.png'];
input=zeros(1,5);
conv1_out_max=zeros(1,5);
conv2_out_max=zeros(1,5);
fc1_out_max=zeros(1,5);
for idx=1:5
a=imread(arr(idx,:));
a=double(a);
XTest1=a/255;
input(idx)=max(max(XTest1));
%CL1
padd='both';
conv1_out=conv_infer(XTest1,W1,b1,pad1,S1,padd);
%Relu
conv1_out_relu=max(conv1_out,0);
%MaxPooling
padd='both';
f_pool1=net.Layers(4,1).PoolSize;
S_pool1=net.Layers(4,1).Stride;
Mpad1=net.Layers(4,1).PaddingSize;
conv1_out_relu=zero_pad(conv1_out_relu,Mpad1(2),padd);
max_pool1=pool_infer(conv1_out_relu,f_pool1,S_pool1);
conv1_out_max(idx)=max(max(max(abs(max_pool1))));
%%CL2
padd='both';
conv2_out=conv_infer(max_pool1,W2,b2,pad2,S2,padd);
%Relu
conv2_out_relu=max(conv2_out,0);
f_pool2=net.Layers(7,1).PoolSize;
S_pool2=net.Layers(7,1).Stride;
Mpad2=net.Layers(7,1).PaddingSize;
conv2_out_relu=zero_pad(conv2_out_relu,Mpad2(2),padd);
max_pool2=pool_infer(conv2_out_relu,f_pool2,S_pool2);
conv2_out_max(idx)=max(max(max(abs(max_pool2))));
%%Flatten
max_poolT=permute(max_pool2,[3 2 1]);
X=max_poolT(:);
%%FC1
[pred g1]= digit_FC(bf1,wf1,X);
fc1_out_max(idx)=max(abs(pred));
end
%CL1
sa0=max(input)/255;
[x1,y1,c1,n1]=size(W1);
Wq1=zeros(x1,y1,c1,n1);
sw1=zeros(1,n1);
sb1=zeros(1,n1);
bq1=zeros(1,1,n1);
for i=1:n1
    sw1(i)=max(max(abs(W1(:,:,:,i))))/127;
    sb1(i)=sa0*sw1(i);
    Wq1(:,:,:,i)=round(W1(:,:,:,i)./sw1(i));
    bq1(i)=round(b1(i)/sb1(i));
end
%CL2
sa1=max(conv1_out_max)/255;
[x2,y2,c2,n2]=size(W2);
Wq2=zeros(x2,y2,c2,n2);
sw2=zeros(1,n2);
sb2=zeros(1,n2);
bq2=zeros(1,1,n2);
for i=1:n2
    sw2(i)=max(max(max(abs(W2(:,:,:,i)))))/127;
    sb2(i)=sa1*sw2(i);
    Wq2(:,:,:,i)=round(W2(:,:,:,i)./sw2(i));
    bq2(i)=round(b2(i)/sb2(i));
end
%FC1
sa2=max(conv2_out_max)/255;
sw3=max(max(abs(wf1)))/127;
sb3=sw3*sa2;
bfq1=round(bf1./sb3);
wfq1=round(wf1./sw3);
sa3=max(fc1_out_max)/127;
%%inference
a=imread('102.png');
XTest1_q=single(a);
a=double(a);
XTest1=a/255;
imshow(a);
%analyzeNetwork(net1)
classes=['0','1','2','3','4','5','6','7','8','9','A','B','C','D','H','K','N','R','U','Y','E','P','S','X','F','L','T','Z','G','O','I','J','M','Q','V','W'];
%%CL1
padd='both';
conv1_out=conv_infer(XTest1,W1,b1,pad1,S1,padd);
conv1_out_q=conv_infer(XTest1_q,Wq1,bq1,pad1,S1,padd);
%Relu
conv1_out_relu=max(conv1_out,0);
conv1_out_relu_q=max(conv1_out_q,0);
%MaxPooling
padd='both';
f_pool1=net.Layers(4,1).PoolSize;
S_pool1=net.Layers(4,1).Stride;
Mpad1=net.Layers(4,1).PaddingSize;
conv1_out_relu=zero_pad(conv1_out_relu,Mpad1(2),padd);
conv1_out_relu_q=zero_pad(conv1_out_relu_q,Mpad1(2),padd);
max_pool1=pool_infer(conv1_out_relu,f_pool1,S_pool1);
max_pool1_q=pool_infer(conv1_out_relu_q,f_pool1,S_pool1);
%Requantization
for i=1:n1
    scale1(i)=sb1(i)/sa1;
    max_pool1_qs(:,:,i)=round(max_pool1_q(:,:,i).*scale1(i));  
end
%%CL2
padd='both';
conv2_out=conv_infer(max_pool1,W2,b2,pad2,S2,padd);
conv2_out_q=conv_infer(max_pool1_qs,Wq2,bq2,pad2,S2,padd);
%Relu
conv2_out_relu=max(conv2_out,0);
conv2_out_relu_q=max(conv2_out_q,0);
f_pool2=net.Layers(7,1).PoolSize;
S_pool2=net.Layers(7,1).Stride;
Mpad2=net.Layers(7,1).PaddingSize;
conv2_out_relu=zero_pad(conv2_out_relu,Mpad2(2),padd);
conv2_out_relu_q=zero_pad(conv2_out_relu_q,Mpad2(2),padd);
max_pool2=pool_infer(conv2_out_relu,f_pool2,S_pool2);
max_pool2_q=pool_infer(conv2_out_relu_q,f_pool2,S_pool2);
%Requantization
for i=1:n2
     scale2(i)=sb2(i)/sa2;
    max_pool2_qs(:,:,i)=round(max_pool2_q(:,:,i).*scale2(i));
end
%%Flatten
max_poolT=permute(max_pool2,[3 2 1]);
max_poolT_q=permute(max_pool2_qs,[3 2 1]);
X=max_poolT(:);
X_q=max_poolT_q(:);
%%FC1
[pred g1]= digit_FC(bf1,wf1,X);
[pred_q g1_q]= digit_FC(bfq1,wfq1,X_q);
scale3=sb3/sa3;
pred_qs=pred_q/scale3;
m = max(pred);
m_q = max(pred_qs);
e = exp(pred-m);
e_q = exp(pred_qs-m_q);
dist = e /sum(e);
dist_q = e_q /sum(e_q);
[score idx]=max(dist);
[score_q idx_q]=max(dist_q);
digit=classes(idx)
digit_q=classes(idx_q)
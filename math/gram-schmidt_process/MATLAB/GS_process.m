function [B] = GS_process(A)
format rat;

n=size(A,2); %Number of columns
B(:,1)=A(:,1); %Set v_1=w_1
    for j=2:n %Loop as many times as there are vectors left to find v_2..v_n
        proj=0;
        for k=1:size(B,2) %Find how many vectors are there in the new basis at this instant
            proj=proj+((dot(A(:,j),B(:,k)))/(norm(B(:,k))^2))*B(:,k); %Find the projection of w_n on each of the vectors already in the basis
        end
        B(:,j)=A(:,j)-proj; %Find w_n minus the sum of the projections
    end


%Normalize it.
for j=1:size(B,2)
    B(:,j)= B(:,j)/norm(B(:,j));
end

end
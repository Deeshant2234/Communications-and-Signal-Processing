%function to check wheather two signal are orthogonal or not
function Product= Orthogonality_Check_Function(A)  
N=10;
Product=zeros(10,10); %creating all zeroes matrix to hold inner product results of every pair of signals
for i=1:N
    for j=i+1:N
        Product(i,j)=round(sum(A(:,i).*A(:,j)),5); %for orthogonality inner product of two vectors is zero
    
        if Product(i,j)==0
            fprintf("Provided two signal i.e. y%i and y%i,are orthogonal to each other \n",i,j)
        else
            fprintf("Provided two signal i.e. y%i and y%i,are not orthogonal to each other \n",i,j)
        end
    end
end
end



function [ yy ] = myfunction( x, y, k, xx )
%MYFUNCTION Summary of this function goes here
%   Detailed explanation goes here
    A = zeros(k, k);
    b = zeros(k,1);
    for i = 1:k
        for j=1:k
            A(i,j) = sum(x.^(i+j-2));
        end
        b(i,1) = sum((x.^(i-1)).*y);
    end
    size(A);
    size(b);
    % c0 = polyfit(x,y,2);
     C = A\b;
     yy = polyval(C,xx);
end

function min = min_row_sum(A)
s = size(A);
minR = 100000;
for i = 1:s(1) % Loops through rows
    rSum = 0;
    for j = 1:s(2) % Loops through colums
        rSum = rSum + A(i,j);
    end
    if rSum < minR
        minR = rSum;
        min = i;
    end
end
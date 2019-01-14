function parity = quotientInBoundsFunc(a, b)
c = a / b;
parity = a < c && b > c;
end
class Solution {
public:
    // a(n + 2) = a(n + 1) + a(n) <=> x^2 - x - 1 = 0 <=> x = phi, 1 - phi
    int climbStairs(int n) {
       double sqrt5 = sqrt(5);
       double phi = (1 + sqrt5) / 2;
       double psi = (1 - sqrt5) / 2;
       n++;
       return round((pow(phi, n) - pow(psi, n))/ sqrt(5));
    }
};

const int MX = 2e5 + 7;
vector<bool> isprime;
vector<ll> primes;
void sieve(int n) {
    primes.clear();          
    isprime.assign(n + 1, false);
    if (n >= 2) {
        isprime[2] = true;
        primes.push_back(2);
    }
    for (int i = 3; i <= n; i += 2)
        isprime[i] = true;

    for (int i = 3; 1LL * i * i <= n; i += 2) {
        if (isprime[i]) {
           
            for (int j = i * i; j <= n; j += 2 * i)
                isprime[j] = false;
        }
    }

    for (int i = 3; i <= n; i += 2)
        if (isprime[i])
            primes.push_back(i);
}

vector<ll> Prime_factor(int n) {
    vector<ll> factor;
    for (ll p : primes) { 
        if (1LL * p * p > n) break;
        if(n%p==0) factor.push_back(p);
        while (n % p == 0) {
            n /= p;
        }
    }
    if (n > 1) factor.push_back(n);
    return factor;
}
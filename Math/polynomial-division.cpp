ll N, M;
          cin >> N >> M;
          vector<ll> A(N + 1);
          for (ll i = 0; i <= N; i++){
            cin >> A[i];
          }
          vector<ll> C(N + M + 1);
          for (ll i = 0; i <= N + M; i++){
            cin >> C[i];
          }
          vector<ll> B(M + 1);
          for (ll i = M; i >= 0; i--){
            B[i] = C[N + i] / A[N];
            for (ll j = 0; j <= N; j++){
              C[i + j] -= A[j] * B[i];
            }
          }
          for (ll i = 0; i <= M; i++){
            cout << B[i];
            if (i < M){
              cout << ' ';
            }
          }
          cout << "\n";
int rain_water(vector<int> &a){

            stack<ll> st;

            ll n=a.size();ll ans=0;
        for(ll i=0;i<n;i++){
                while(!st.empty() and a[st.top]<a[i]){
                        ll cur=st.top();
                        st.pop();
                        if(st.empty()) break;

                    ll diff=i- st.top()-1;

                    ans+=min(a[st.top()],a[i])-a[cur];
                    ans*=diff;
                }
                st.push(i);
        }

       return ans;
}

class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        vector<string> invalidTrans;
        int n=transactions.size();
        vector<string> name(n),city(n);
        vector<int> time(n),amount(n),invalid(n,0);
        for(int i=0;i<n;i++){
            string str = transactions[i];
            vector<string> v;
            stringstream ss(str);
            while (ss.good()) {
                string substr;
                getline(ss, substr, ',');
                v.push_back(substr);
            }
            name[i]=v[0];
            time[i]=stoi(v[1]);
            amount[i]=stoi(v[2]);
            city[i]=v[3];
        }
        //cout<<n<<" ";
        for(int i=0;i<n;i++){
            cout<<amount[i]<<" ";
            if(amount[i]>1000){
                invalid[i]=1;
            }
            for(int j=i+1;j<n;j++){
                if(name[i]==name[j] and abs(time[i]-time[j])<=60 and city[i]!=city[j]){
                    invalid[i]=1;
                    invalid[j]=1;
                }
            }
        }
        for(int i=0;i<n;i++){
            if(invalid[i]){
                invalidTrans.push_back(transactions[i]);
            }
        }
        return invalidTrans;
    }
};
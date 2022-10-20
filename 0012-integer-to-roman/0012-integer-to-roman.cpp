class Solution {
public:
    string intToRoman(int num) {
        map<int,string> m;
        m[1]="I";
        m[2]="II";
        m[3]="III";
        m[4]="IV";
        m[5]="V";
        m[6]="VI";
        m[7]="VII";
        m[8]="VIII";
        m[9]="IX";
        m[10]="X";
        m[40]="XL";
        m[50]="L";
        m[90]="XC";
        m[100]="C";
        m[400]="CD";
        m[500]="D";
        m[900]="CM";
        m[1000]="M";
        string roman="";
        for(auto itr=m.rbegin();itr!=m.rend();itr++){
            if(num>=itr->first){
                int c=num/itr->first;
                num=num-c*itr->first;
                while(c--){
                    roman+=itr->second;
                }
            }
        }
        return roman;
    }
};
class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded_string="";
        for(string &i:strs){encoded_string+=to_string(i.length())+"#"+i;}
        return encoded_string;
    }

    vector<string> decode(string s) {
        vector<string>decoded_strs;
        int i=0;//#
        int j=0;//begining
        while(j<s.length()){
        while(s[i]!='#'){i++;}
        int len=stoi(s.substr(j,i-j));
        string ss=s.substr(i+1,len);
        decoded_strs.push_back(ss);
        j=i+1+len;
        i=j;
    }
    return decoded_strs;
    }
};

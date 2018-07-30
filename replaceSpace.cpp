class Solution {
public:
	void replaceSpace(char *s, size_t len){
        string in(s, len);//char * to string
        int count=0;
        string rec;
        vector<string> vec_str;
        
        size_t bef=0, aft=0;
        while(1){
        	string temp_word;
            aft = in.find_first_of(' ', bef); 
            if(aft == string::npos){
                temp_word = in.substr(bef);
                vec_str.push_back(temp_word);
                break;
            }
            else{
                temp_word = in.substr(bef, aft-bef);
                vec_str.push_back(temp_word);
                bef = aft+1;
            }
            
        }
        for(size_t i=0; i<vec_str.size(); ++i){
            if(i == vec_str.size()-1){
                rec += vec_str[i];
            }
            rec += vec_str[i];
            rec += "%20";
        }
        strcpy(s, rec.c_str());//string to char *, c_str() return const char *, so can't assign directily
        return;
    }
};

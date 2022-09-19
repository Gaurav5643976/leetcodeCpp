class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
     
        vector<vector<string>>duplicates;
        unordered_map<string,vector<string>>uniqueContent;
            
        for(string path:paths){
            
            int j=0;
            
            //directory
            string directory="";
            while(j<path.length() && path[j]!=' '){
                directory+=path[j];
                j++;
            }
            j++;
            
            //files
            while(j<path.length()){
                
                //fileName
                string fileName="";
                while(j<path.length() && path[j]!='('){
                    fileName+=path[j];
                    j++;
                }
                j++;
                
                //fileContent
                string fileContent="";
                while(j<path.length() && path[j]!=')'){
                    fileContent+=path[j];
                    j++;
                }
                j+=2;
                
                string filePath=directory+"/"+fileName;
                // cout<<j<<" "<<filePath<<"\n";
                
                uniqueContent[fileContent].push_back(filePath);
        
            }
        }
        
        for(auto content:uniqueContent){
            if(content.second.size()>1){
                duplicates.push_back(content.second);
            }
        }
        
        return duplicates;
    }
};
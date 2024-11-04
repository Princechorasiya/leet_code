class Solution {
public:
    string compressedString(string word) {
        int n = word.size();
        int i=1;
        char prev =word[0];
        string comp;
        int count=1;
        for(int i=1;i<n;i++){
            //process till we reach last character 
            if(word[i]!=prev){
                //simply append 
                for(int j=0;j<count/9;j++){
                    comp+='9';
                    comp+=prev;
                }
                count =count%9;
                if(count >0){
                    comp+=to_string(count);
                    comp+=prev;
                }

                prev =word[i];
                count =1;
                
            }else{
                count++;
            }
        }
        //process the remaining 
        for(int j=0;j<count/9;j++){
                    comp+='9';
                    comp+=prev;
                }
        count =count%9;
        if(count >0){
                    comp+=to_string(count);
                    comp+=prev;
                }

        return comp;

    }
};
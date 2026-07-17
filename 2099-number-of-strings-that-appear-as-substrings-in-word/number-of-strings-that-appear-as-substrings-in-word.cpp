// class Solution {
// public:
//     int numOfStrings(vector<string>& patterns, string word) {
//         int n=patterns.size();
//         int count=0;
//         for(int i=0;i<n;i++){
//             for(int j=0;j<word.size();j++){
//             if(patterns[j]==word[j]){
//                 count++;
//             }
//          }
//         }
//         return count;
//     }
// };
// class Solution {
// public:
//     int numOfStrings(vector<string>& patterns, string word) {    
//         int count = 0;
//         for(int i = 0; i < patterns.size(); i++) {
//             string p = patterns[i];
//             for(int j = 0; j <= word.size() - p.size(); j++) {
//                 if(word.substr(j, p.size()) == p) {
//                     count++;
//                     break;
//                 }
//             }
//         }
//         return count;
//     }
// };

class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {

        int count = 0;

        for(int i = 0; i < patterns.size(); i++) {

            string p = patterns[i];

            if(p.size() > word.size())
                continue;

            for(int j = 0; j <= word.size() - p.size(); j++) {

                string temp = "";

                for(int k = j; k < j + p.size(); k++) {
                    temp += word[k];
                }

                if(temp == p) {
                    count++;
                    break;
                }
            }
        }

        return count;
    }
};
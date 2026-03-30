class Solution {
public:
    string reorderSpaces(string text) {
        int spaces = 0;
        vector<string>words;
        string word = "";
        int n = text.size();
        for(int i = 0;i<n;i++)
        {
            if(text[i] == ' ')
            {
                spaces++;
                    if(word != "")
                    {
                        words.push_back(word);
                        word = "";
                    }
                }
                else
                {
                    word += text[i];
                }
            }
            if(word != "")
            {
                words.push_back(word);
            }
            int wordCount = words.size();
            if(wordCount == 1)
            {
                return words[0]+string(spaces,' ');
            }
            int gap= spaces/(wordCount - 1);
            int extra = spaces %(wordCount-1);
            string result="";
            for(int i = 0;i<wordCount;i++)
            {
                result += words[i];
                if(i<wordCount -1)
                {
                    result += string(gap,' ');
                }
            }
            result += string(extra, ' ');
            return result;
        }
};
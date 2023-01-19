#include <iostream>
#include <vector>

size_t duplicateCount(const std::string &in) // helper for tests
{
    std::string text = in;
    std::vector<char> out;
    for (int i = 0; i < text.size(); i++)
    {
        out.push_back(tolower(text[i]));
    }
    int count_doubles = 0;
    for (int i=0; i < out.size(); i++)
    {
        while(out[i]=='\0') i++;
        char ref = out[i];
        int count=0;
        for (int j = i; j < out.size(); j++)
        {
            if (out[j]==ref)
            {
                count++;
                out[j]='\0';
            }
        }
        if(count>=2) count_doubles++;
    }
    return count_doubles;
}

int main()
{
    std::string a;
    std::cin >> a;
    std::cout << duplicateCount(a) << std::endl;
    return 0;
}

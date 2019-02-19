#include <iostream>
#include <chrono>
#include <string>
#include <random>
#include <cassert>
#include <stack>

struct TimeToRun
{
    typedef std::chrono::high_resolution_clock::time_point moment;

    TimeToRun(char const* string)
    {
        str = string;
        t_start = std::chrono::high_resolution_clock::now();
    }
    ~TimeToRun()
    {
        using namespace std::chrono;
        moment t_end = high_resolution_clock::now();
        duration<double> time_span = duration_cast<duration<double>>(t_end - t_start);
        std::cout << str << "\t= " << time_span.count() << " seconds.\n";
    }
private:
    moment t_start;
    char const* str = nullptr;
};

std::string generateXYZ(size_t length)
{
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> dis(1, 3);

    std::string s("");
    for (size_t i = 0; i < length; ++i)
    {
        switch (dis(gen))
        {
        case 1:
            s.push_back('X');
            break;
        case 2:
            s.push_back('Y');
            break;
        case 3:
            s.push_back('Z');
            break;
        }
    }
    assert(s.length() == length);

    return s;
}

std::string original(std::string &S)
{
    TimeToRun t("Interview");
    std::string str = S;
    while (true)
    {
        bool nothing_to_do = true;
        std::string next;
        if (str.size() == 0)
            return "";
        for (size_t i = 0; i < str.size() - 1;)
        {
            if (str.at(i) == str.at(i + 1))
            {
                ++i;
                nothing_to_do = false;
            }
            else
                next.push_back(str.at(i));
            ++i;
            if (i == str.size() - 1)
                next.push_back(str.at(i));
        }

        if (nothing_to_do)
            break;
        else
            str.assign(next);
    }

    return str;
}

std::string stack(std::string &S)
{
    TimeToRun t("Stack\t");

    if (S.size() == 0)
        return "";

    std::stack<char>st;
    st.push(S.at(0));

    for (size_t i = 1; i < S.size(); ++i)
    {
        if (st.empty() || st.top() != S.at(i))
            st.push(S.at(i));
        else
            st.pop();
    }

    std::string str;
    while (!st.empty())
    {
        str.insert(str.begin(), st.top());
        st.pop();
    }

    return str;
}

std::string stringAsStack(std::string &S)
{
    TimeToRun t("String as stack");

    if (S.size() == 0)
        return "";

    std::string str;
    int i_str = 0;
    int i_stack = 0;
    str.push_back(S.at(0));

    for (size_t i = 1; i < S.size(); ++i)
    {
        if (i_str < 0) // stack empty
        {
            i_str = 0;
            str.at(i_str) = S.at(i);
        }
        else if (str.at(i_str) != S.at(i))
        {
            if (str.length() == i_str + 1)
            {
                str.push_back(S.at(i));
                i_str++;
            }
            else
                str.at(++i_str) = S.at(i);
        }
        else
        {
            i_str--;
        }
    }

    if (i_str < 0)
        return "";
    return str.substr(0, i_str + 1);
}

void noSTL(const char*S, char* sol)
{
    TimeToRun t("Without STL");
    size_t len = strlen(S);
    if (len == 0)
    {
        sol[0] = '\0';
        return;
    }

    int i_str = 0;
    int i_stack = 0;
    sol[0] = S[0];

    for (size_t i = 1; i < len; ++i)
    {
        if (i_str < 0) // stack empty
        {
            i_str = 0;
            sol[i_str] = S[i];
        }
        else if (sol[i_str] != S[i])
        {
            sol[++i_str] = S[i];
        }
        else
        {
            i_str--;
        }
    }

    if (i_str < 0)
        sol[0] = '\0';
    else
        sol[i_str + 1] = '\0';
}

int main()
{
    std::string arg = generateXYZ(100000);
    std::string sol1 = original(arg);
    std::string sol2 = stack(arg);
    assert(sol1.compare(sol2) == 0);
    std::string sol3 = stringAsStack(arg);
    assert(sol2.compare(sol3) == 0);
    char sol[100000];
    noSTL(arg.c_str(), sol);
    assert(strcmp(sol, sol1.c_str())==0);
}

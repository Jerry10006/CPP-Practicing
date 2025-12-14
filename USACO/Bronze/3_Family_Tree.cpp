//這題僅部分AC，可能有條件沒找到，11/15 AC
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <vector>
using namespace std;

int Same(const string& Name, const string& Target, unordered_map<string, vector<string>>& DOWN)
{
    if (Name == Target) return 1;
    if (DOWN[Name].empty()) return 0;

    for (const string& N : DOWN.at(Name))
    {
        const int val = Same(N, Target, DOWN);
        if (val != 0) return val + 1;
    }
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("family.in", "r", stdin);
    freopen("family.out", "w", stdout);

    int N;
    string TargetA, TargetB;
    unordered_map<string, string> UP;
    unordered_map<string, vector<string>> DOWN;
    cin >> N >> TargetA >> TargetB;

    for (int i = 0; i < N; i++)
    {
        string A, B;
        cin >> A >> B;
        DOWN[A].push_back(B);
        UP[B] = A;
    }
    if (!UP.count(TargetA) || !UP.count(TargetB))
    {
        cout << "NOT RELATED";
        return 0;
    }
    unordered_set<string> ancestor;
    string TargetBAncestor = TargetB;
    string TargetAAncestor = TargetA;
    ancestor.insert(TargetA);
    while (!UP[TargetAAncestor].empty())
    {
        ancestor.insert(UP[TargetAAncestor]);
        TargetAAncestor = UP[TargetAAncestor];
    }
    while (ancestor.find(TargetBAncestor) == ancestor.end())
    {
        if (UP[TargetBAncestor].empty())
        {
            cout << "NOT RELATED";
            return 0;
        }
        TargetBAncestor = UP[TargetBAncestor];
    }
    string LCA = TargetBAncestor;
    if (find(DOWN[LCA].begin(), DOWN[LCA].end(), TargetA) != DOWN[LCA].end() && find(DOWN[LCA].begin(), DOWN[LCA].end(), TargetB) != DOWN[LCA].end())
    {
        cout << "SIBLINGS";
        return 0;
    }
    if (LCA == TargetA)
    {
        int times = Same(TargetA, TargetB, DOWN);
        if (times != 0)
        {
            if (times == 1) cout << TargetA << " is the mother of " << TargetB;
            if (times == 2) cout << TargetA << " is the grand-mother of " << TargetB;
            if (times > 2)
            {
                string relationship = "grand-mother";
                for (int i = 0; i < times - 2; i++) relationship = "great-" + relationship;
                cout << TargetA << " is the " << relationship << " of " << TargetB;
            }
            return 0;
        }
    }
    if (LCA == TargetB)
    {
        int times = Same(TargetB, TargetA, DOWN);
        if (times != 0)
        {
            if (times == 1) cout << TargetB << " is the mother of " << TargetA;
            if (times == 2) cout << TargetB << " is the grand-mother of " << TargetA;
            if (times > 2)
            {
                string relationship = "grand-mother";
                for (int i = 0; i < times - 2; i++) relationship = "great-" + relationship;
                cout << TargetB << " is the " << relationship << " of " << TargetA;
            }
            return 0;
        }
    }
    if (find(DOWN[LCA].begin(), DOWN[LCA].end(), TargetA) != DOWN[LCA].end()) //TargetA is the aunt of TargetB
    {
        int times = Same(LCA, TargetB, DOWN); // times記得-1，因為在這邊LCA不用算是一個
        times--;
        if (times != 0)
        {
            if (times == 1) cout << TargetA << " is the aunt of " << TargetB;
            if (times > 1)
            {
                string relationship = "aunt";
                for (int i = 0; i < times - 2; i++) relationship = "great-" + relationship;
                cout << TargetA << " is the " << relationship << " of " << TargetB;
            }
            return 0;
        }
    }
    if (find(DOWN[LCA].begin(), DOWN[LCA].end(), TargetB) != DOWN[LCA].end()) //TargetB is the aunt of TargetA
    {
        int times = Same(LCA, TargetA, DOWN); // times記得-1，因為在這邊LCA不用算是一個
        times--;
        if (times != 0)
        {
            if (times == 1) cout << TargetB << " is the aunt of " << TargetA;
            if (times > 1)
            {
                string relationship = "aunt";
                for (int i = 0; i < times - 2; i++) relationship = "great-" + relationship;
                cout << TargetB << " is the " << relationship << " of " << TargetA;
            }
            return 0;
        }
    }
    cout << "COUSINS";
    return 0;
}
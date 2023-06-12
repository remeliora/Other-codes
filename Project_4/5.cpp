#include <iostream>
#include <cctype>
using namespace std;
class TString
{
private:
    size_t Size;
    char Str[10];
    friend istream& operator(istream&, TString&);
public:
    explicit TString() Size(0)
    {
    }
    inline size_t size() const
    {
        return Size;
    }
    size_t hash() const
    {
        constexpr int p = 31;
        size_t res = 0, power = 1;
        for (size_t i = 0; i  Size; ++i)
        {
            res += (Str[i] - 'a' + 1)  power;
            power = p;
        }
        return res;
    }
    inline char operator[](size_t i) const
    {
        return Str[i];
    }
    bool operator==(const TString& op) const
    {
        if (size() != op.size()) return false;
        for (size_t i = 0; i  size(); ++i) if (Str[i] != op[i]) return false;
        return true;
    }
    inline bool operator!=(const TString& op) const
    {
        return !(this == op);
    }
};
istream& operator(istream& in, TString& str)
{
    while (isspace(in.peek())) in.get();
    size_t i;
    for (i = 0; !isspace(in.peek()); ++i) str.Str[i] = in.get();
    str.Size = i;
    return in;
}
class TList
{
    struct TNode
    {
        TString Data;
        TNode Next;
        explicit TNode(const TString& data)  Data(data), Next(nullptr) {}
    };
private
    TNode Head;
    void _free(TNode ptr)
    {
        if (ptr == nullptr) return;
        _free(ptr-Next);
        delete ptr;
    }
public
    explicit TList()  Head(nullptr) {}
    void Add(const TString& data)
    {
        TNode ptr = new TNode(data);
        ptr-Next = Head;
        Head = ptr;
    }
    TList(const TList& op)  Head(op.Head) {}
    TList& operator=(const TList& op)
    {
        Head = op.Head;
        return this;
    }
    bool Find(const TString& data) const
    {
        TNode ptr = Head;
        while (ptr != nullptr && ptr-Data != data) ptr = ptr-Next;
        return ptr != nullptr;
    }
    ~TList()
    {
        _free(Head);
    }
};
class StringSet
{
private
    size_t HashMapLength;
    TList Set;
    inline TList& item(const TString& str) const
    {
        return Set[str.hash() % HashMapLength];
    }
public
    explicit StringSet()  HashMapLength(1000000), Set(nullptr)
    {
        Set = new TList[HashMapLength];
    }
    StringSet(const StringSet& op)  HashMapLength(op.HashMapLength), Set(op.Set) {}
    StringSet& operator=(const StringSet& op)
    {
        HashMapLength = op.HashMapLength;
        Set = op.Set;
        return this;
    }
    void Add(const TString& str)
    {
        item(str).Add(str);
    }
    bool Find(const TString& str) const
    {
        return item(str).Find(str);
    }
    ~StringSet()
    {
        if (Set != nullptr)
        {
            delete[] Set;
        }
    }

};
enum class Func
{
    Add,
    Find,
    Stop,
    Unknown
};
inline Func convert(char op)
{
    switch (op)
    {
    case '+'
        return FuncAdd;
    case ''
        return FuncFind;
    case '#'
        return FuncStop;
    default
        return FuncUnknown;
    }
}
int main()
{
    StringSet set;
    char op;
    while (convert(op = cin.get()) != FuncStop)
    {
        TString str;
        cin  str;
        switch (convert(op))
        {
        case FuncAdd
            set.Add(str);
            break;
        case FuncFind
            if (set.Find(str)) cout  YES  'n';
            else cout  NO  'n';
            break;
        default
            break;
        }
        while (isspace(stdcin.peek())) cin.get();
    }
    return 0;
}
class trie {
    struct node {
        int words;
        int prefix;
        struct node * edge[26];
    };
    struct node *root;
public:
    trie() {
        root = newnode();
        root -> words = 0;
        root -> prefix = 0;
        for(int i = 0;i < 26;i++)
            root -> edge[i] = NULL;
    }
    struct node * newnode() {
        struct node *x = (struct node *)malloc(sizeof(struct node));
        return x;
    }
    void add(string s) {
        struct node *x = root;
        for(auto i: s) {
            x -> prefix += 1;
            if(x -> edge[i-'a'] == NULL) {
                x -> edge[i-'a'] = newnode();
            }
            x = x -> edge[i-'a'];
        }
        x -> words += 1;
    }
    int cword(string s) {
        struct node *x = root;
        for(auto i: s) {
            if(x -> edge[i-'a'] == NULL)
                return 0;
            x = x -> edge[i-'a'];
        }
        return x -> words;
    }
    int cprefix(string s) {
        struct node *x = root;
        for(auto i: s) {
            if(x -> edge[i-'a'] == NULL)
                return 0;
            x = x -> edge[i-'a'];
        }
        return x -> prefix;
    }
};

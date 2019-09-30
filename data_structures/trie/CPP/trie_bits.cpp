class trie {
    struct node {
        int words;
        int prefix;
        struct node *edge[2];
    };
public:
    struct node *root;
    trie() {
        root = newnode();
        root -> words = 0;
        root -> prefix = 0;
        root -> edge[0] = root -> edge[1] = NULL;
    }
    struct node * newnode() {
        struct node *x = (struct node *)malloc(sizeof(struct node));
        return x;
    }
    void to_bits(int a[],int n) {
        for(int i = 0;i < 32;i++) {
            a[i] = n%2; n /= 2;
        }
        reverse(a,a+32);
    }
    void add(int n) {
        int bits[32];
        to_bits(bits,n);
        struct node *x = root;
        for(auto i: bits) {
            x -> prefix += 1;
            if(x -> edge[i] == NULL)
                x -> edge[i] = newnode();
            x = x -> edge[i];
        }
        x -> words += 1;
    }
    int cword(int n) {
        int bits[32]; to_bits(bits,n);
        struct node *x = root;
        for(auto i: bits) {
            if(x -> edge[i] == NULL)
                return 0;
            x = x -> edge[i];
        }
        return x -> words;
    }
};

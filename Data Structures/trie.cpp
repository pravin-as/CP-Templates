// Make "Trie tr;". 
// uncomment B and base if want to work with strings.
// For finding min/max xor with some random number k put all 
// numbers of array in trie then find min/max but if want to
// find pair with min/max xor and both numbers in array then firstly
// only insert first number in trie then keep on inserting later numbers
// along with finding min/max.
// containsKey, get etc. have attribute as char.

/*tr.insertInteger(arr[0]);for(int i = 1; i < n; i++){
 mn = min(mn, tr.minXor(arr[i]));tr.insertInteger(arr[i]);} */

struct Node{

    const static int B = 2; 
    // const static int B = 26;
    Node *links[B];
    int cntEndWith = 0;
    int cntPrefix = 0;
    char base = '0';
    // char base = 'a';

    bool containsKey(char ch){
        return (links[ch - base] != NULL);
    }
    Node* get(char ch){
        return links[ch - base];
    }
    void put(char ch, Node* node){
        links[ch - base] = node;
    }
    void increaseEnd(){
        cntEndWith++;
    }
    void increasePrefix(){
        cntPrefix++;
    }
    void deleteEnd(){
        cntEndWith--;
    }
    void reducePrefix(){
        cntPrefix--;
    }
    int getEnd(){
        return cntEndWith;
    }
    int getPrefix(){
        return cntPrefix;
    }

};


class Trie{

public:
    Node *root;
    Trie(){
        root = new Node();
    }

    void insert(string word){
        Node *node = root;
        for(int i = 0; i < word.length(); i++){
            if(!node -> containsKey(word[i])){
                node -> put(word[i], new Node());
            }
            node = node -> get(word[i]);
            node -> increasePrefix();
        }
        node -> increaseEnd();
    }

    int countWordsEqualTo(string word){
        Node *node = root;
        for(int i = 0; i < word.length(); i++){
            if(node -> containsKey(word[i])){
                node = node -> get(word[i]);
            }else{
                return 0;
            }
        }
        return node -> getEnd();
    }

    int countWordsStartingWith(string word){
        Node *node = root;
        for(int i = 0; i < word.length(); i++){
            if(node -> containsKey(word[i])){
                node = node -> get(word[i]);
            }else{
                return 0;
            }
        }
        return node -> getPrefix();
    }

    void erase(string word){
        if(!check(word)) return;
        Node *node = root;
        for(int i = 0; i < word.length(); i++){
            if(node -> containsKey(word[i])){
                node = node -> get(word[i]);
                node -> reducePrefix();
            }else{
                return;
            }
        }
        node -> deleteEnd();
    }

    bool check(string word){
        Node *node = root;
        for(int i = 0; i < word.length(); i++){
            if(node -> containsKey(word[i])){
                node = node -> get(word[i]);
            }else{
                return false;
            }
        }
        return true;
    }

    string integerToBin(int num){
        string word = "";
        for(int i = 31; i >= 0; i--){
            int bit = ((num >> i) & 1);
            word += to_string(bit);
        }
        return word;
    }

    void insertInteger(int num){
        string word = integerToBin(num);
        insert(word);
    }

    int maxXor(int num){
        Node* node = root;
        int maxNum = 0;
        for(int i = 31; i >= 0; i--){
            int bit = ((num >> i) & 1);
            char BIT = (bit + '0'), NOTBIT = (!bit + '0');
            if(node -> containsKey(NOTBIT)){
                maxNum = (maxNum | (1 << i));
                node = node -> get(NOTBIT);
            }else{
                node = node -> get(BIT);
            }
        }
        return maxNum;
    }

    int minXor(int num){
        Node* node = root;
        int minNum = 0;
        for(int i = 31; i >= 0; i--){
            int bit = ((num >> i) & 1);
            char BIT = (bit + '0'), NOTBIT = (!bit + '0');
            if(node -> containsKey(BIT)){
                node = node -> get(BIT);
                minNum = (minNum << 1);
            }else{
                node = node -> get(NOTBIT);
                minNum = (minNum << 1);
                minNum++;
            }
        }
        return minNum;
    }

    // Number of values such that val ^ x < k
    int query(int x, int k){
        Node* node = root;
        int ans = 0;
        for(int i = 31; i >= 0; i--){
            if(node == NULL)break;
            int b1 = (x >> i & 1), b2 = (k >> i & 1);
            char BIT1 = (b1 + '0'), NOTBIT1 = (!b1 + '0'), BIT2 = (b2 + '0'), NOTBIT2 = (!b2 + '0');
            if(b2 == 1){
                if(node -> containsKey(BIT1)){
                    ans += node -> get(BIT1) -> cntPrefix;
                }
                node = node -> get(NOTBIT1);
            }else{
                node = node -> get(BIT1);
            }
        }
        return ans;
    }


};
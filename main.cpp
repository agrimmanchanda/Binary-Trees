#include <iostream>
#include <string>
#include <vector>

struct bdnode{
    std::string val;
    bdnode* left;
    bdnode* right;
};

typedef bdnode* bdt;

bdt buildbdt(const std::vector<std::string>& fvalues);
std::string evalbdt(bdt t, const std::string& input);
bdt createTree(int xn, int nodeHeight);
void createPath(bdt treenode, const std::string& temp);

//// FOR TESTING ONLY ////-----------------------------------------------
void generate_combinations(std::string current, int len, std::vector<std::string>& combinations){
    if(len == 0){
        combinations.push_back(current);
        return;
    }
    generate_combinations(current + "0", len - 1, combinations);
    generate_combinations(current + "1", len - 1, combinations);
}

void test_all(int len, bdt tree){
    std::vector<std::string> combinations;
    generate_combinations("", len, combinations);
    for(std::string combination: combinations)
        std::cout << combination << ": " << evalbdt(tree, combination) << std::endl;
}
////---------------------------------------------------------------------

int main(){
    //testing an or tree
    std::vector<std::string> input;
    //std::string in = "111010";
    std::string in = "000000";
    input.push_back(in);

    //in = "010100";
    in = "000001";
    input.push_back(in);

    //in = "001000";
    in = "000010";
    input.push_back(in);

    //in = "000000";
    in = "000011";
    input.push_back(in);

    //in = "101000";
    in = "000100";
    input.push_back(in);

    input.push_back(in);
    bdt hdtree = NULL;
    hdtree = buildbdt(input);

    int len = input[0].length();
    test_all(len, hdtree);

    return 0;
}

//function should return a pointer to the root of tree created
bdt buildbdt(const std::vector<std::string>& fvalues){

    int nodeNumber = 1;
    int createHeight = fvalues[0].size();
    bdt hdtree = createTree(nodeNumber, createHeight);

    for (int i = 0; i < fvalues.size(); i++){
        std::string temp = fvalues[i];
        createPath(hdtree, temp);
    }

    return hdtree;
}


//function will return a string with value of the boolean function (0 or 1).
std::string evalbdt(bdt t, const std::string& input){

    for (int i = 0; i < input.length(); i++){

        if (input[i] == '0'){
            t = t->left;
        }
        else{
            t = t->right;
        }
    }

    return t->val;
}

//makes a new binary tree with 0s in the leaves and xn as the relevant nodes
bdt createTree(int xn, int nodeHeight){

    bdt tmptree = new bdnode;
    if (nodeHeight == 0){ //condition for base case
        tmptree->val = "0";
        tmptree->left = NULL;
        tmptree->right = NULL;
    }
    else{
        tmptree->val = "x" + std::to_string(xn); //create name of nodes starting from x1
        tmptree->left = createTree(xn + 1, nodeHeight - 1);
        tmptree->right = createTree(xn + 1, nodeHeight - 1);
    }
    return tmptree;
}

void createPath(bdt treenode, const std::string& temp){

    for (int digit = 0; digit < temp.length(); digit++){

        if (temp[digit] == '0'){   //set all zeros in leaves
            treenode = treenode->left;
        }
        else {
            treenode = treenode->right;
        }
    }

    treenode->val = "1";  //set 1 in the required pathway
}

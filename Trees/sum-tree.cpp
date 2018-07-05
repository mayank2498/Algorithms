/*


https://practice.geeksforgeeks.org/problems/sum-tree/1

*/

bool checkleaf(Node * x){
    if(x==NULL){return true;}
    if(x->left == NULL && x->right==NULL){
        return true;
    }
    return false;
}

bool isSumTree(Node* root){
    queue<Node *> q;
    if(root==NULL){return true;}
    q.push(root);
    while(!q.empty()){
        Node * x = q.front();
        q.pop();
        Node * l = x->left;
        Node * r = x->right;

        int sum = 0;
        if( !checkleaf(l) ){  sum += 2*(l->data);   q.push(l);}
        else if(l!=NULL){ sum += l->data; }
        
        if( !checkleaf(r) ){  sum += 2*(r->data);   q.push(r);}
        else if(r!=NULL){ sum += r->data; } 
       
        if(sum!=x->data){
            return false;
        }
    }
    return true;
}

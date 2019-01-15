/*

https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1

*/


void leftView(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    bool got_first = true;
    while( 1 ){
        Node * x = q.front();
        q.pop();
        if(x==NULL){
            got_first = true;
             if(q.empty()){break;}
            q.push(NULL);
        }
        else{
            // print first node of the level and reset got_first
            if(got_first){
                cout<<x->data<<" ";
                got_first = false;
            }
            if(x->left!=NULL)
                q.push(x->left);
            if(x->right!=NULL)
                q.push(x->right);
        }
    }
}

List Merge( List L1, List L2 ){
    
    if(L1==NULL&&L2==NULL){
        return NULL;
    }
    List p1=L1->Next;
    List p2=L2->Next;
    List list=(List)malloc(sizeof(List));
    list->Next=NULL;
    List p=list;
    
    while(p1&&p2){
        if(p1->Data<p2->Data){
            p->Next=p1;
            p1=p1->Next;
        }else{
            p->Next=p2;
            p2=p2->Next;
        }
        p=p->Next;
    }
    if(p1) p->Next = p1;
    if(p2) p->Next = p2;
    L1->Next=NULL;
    L2->Next=NULL;
    return list;
}
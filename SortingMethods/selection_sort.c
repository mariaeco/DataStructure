selection_sort(v[], n){//v = vetor
    int my_id;
    for (int i=0; i < n-2; i++){
        my_id = i;
        for (int j = i+1; j < n-1; j++){
            if(v[my_id]>v[j]){
                my_id = j;
            }
        }

        aux = v[i];
        v[i] = v[my_id];
        v[my_id]=aux;

    }
}

insertion_sort(){


    
}
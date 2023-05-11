class DBinarySearch{

	public:
		int** ptr;
		DBinarySearch();
		DBinarySearch(int n);
		bool insert(int n);
		int find(int target){return search(target,0);};
		void deletion(int target);
		bool remove(int target);
		int get(int index);
		void print_element();
	private:
		int  N, maxLayer, base;
		bool** isDelete;
		bool* isFull;
		int* numDelete;
		int max(int a,int b){ return (a>b) ? a : b;};
		int len(int layer){return (1<<layer);};
		int search(int layer, int target);
		void merge(int* l0, int* l1, bool* del_0, bool* del_1, int layer);
		void resize(int sizeLayer);
		void push(int* list, bool* res_del, int layer);
};

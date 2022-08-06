#include <iostream>

struct point {
	point(){}
	point(float _x, float _y) : x(_x), y(_y) {}
	float x;
	float y;
};


struct quadtree {
	point mid_point;
	point p;
	quadtree(point _mid_point, point _p) : mid_point(_mid_point), p(_p) {
		ul = nullptr;
		ur = nullptr;
		ll = nullptr;
		lr = nullptr;
	}
	quadtree *ul;
	quadtree *ur;
	quadtree *ll;
	quadtree *lr;

	void insert(point p){
	if(p.x > 0 && p.x < mid_point.x && p.y > mid_point.y && p.y < mid_point.y*2.0){
		if(this->ul == nullptr)
			this->ul = new quadtree(point(mid_point.x/2, mid_point.y/2),p);
		else
			this->ul->insert(p);
	}
	}

	void print(){
		quadtree *current = this;
		std::cout  
			<<"Mid point: "<<current->mid_point.x<<' '<<current->mid_point.y
			<<" Point: "<<current->p.x<<' '<<current->p.y
			<<std::endl;
		if(current->ul == nullptr)
			return;
		current = current->ul;
		current->print();
	}

};

int main(){
	float width = 800.0f;
	float height = 600.0f;

	point root_point(width/2,height/2);
	quadtree *root = new quadtree(root_point, point(0,0));
	point leaf(1.0f,550.0f);
	point leaf1(2.0f,550.0f);

	root->insert(leaf);
	root->insert(leaf1);
	root->print();

	return 0;
}

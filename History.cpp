#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

template <class t2>
class History {

private:
	vector<t2> _undo;
	vector<t2> _redo;
	t2* _data;


public:
	History(t2 data) :_undo(), _redo() {
		_data = new t2(data);
	}
	bool canundo() {
		return _undo.size() > 0;
	}
	bool canredo() {
		return _redo.size() > 0;
	}
	void change(t2 NewData) {
		cout << "change: " << *_data << "->" << NewData << endl;
		_undo.push_back(t2(*_data));
		_data = new t2(NewData);
		_redo.clear();
	}
	void undo() {
		if (canundo()) {
			cout << "UNDO: " << endl;
			_redo.push_back(t2(*_data));
			_data = new t2(_undo.back());
			_undo.pop_back();
		}
		else {
			cout << "Undo can not do!" << endl;
		}
	}
	void redo() {
		if (canredo()) {
			cout << "REDO: " << endl;
			_undo.push_back(t2(*_data));
			_data = new t2(_redo.back());
			_redo.pop_back();
		} else {
			cout << "Redo can not do!" << endl;
		}
	}
	void print() {
		cout << *_data << endl;
	}
};
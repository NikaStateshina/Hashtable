#pragma once
#include "Employee.h"
#include "AdditionalFunctions.h"

class HashTable{

	private:
		Employee* table;
		int* status;
		unsigned N;

	public:
		
		HashTable(unsigned _N) {
			table = new Employee[_N];
			N = _N;
			status = new int[_N];
			for (int i = 0; i < _N; i++) {
				status[i] = 0;
			}
		}

		~HashTable() {
			delete [] table;
			delete [] status;
		}
		
		int GetSize() const{
			return N;
		}

		friend ostream& operator << (ostream& os, const HashTable& ht) {
			for (int i = 0; i < ht.N; i++) {
				os << "[" << i << "] |" << ht.status[i] << "| " << ht.table[i] << endl;
			}
			return os << endl;
		}

		//���-������� 1,
		//���������� ��������� �������� ��������� � �������������
		int HashFunc1(Employee rec) {
			int hf1;
			hf1 = (GetStrSum(rec.prof) + rec.period) % N;
			return hf1;
		}


		//���-������� 2, ������������ ����������� (+i*i)
		//adr - ����� ���������� ������; int i - ����� �������
			int HashFunc2(int adr, int i) {			
				return (adr + i * i) % N;		    
		}


		//����� ������ � �������
		bool SearchRec(Employee rec) {
			int adrr = HashFunc1(rec);
			int adr = adrr;
			if ((rec == table[adr]) && (status[adr] == 1))
				return true;
			int i = 1;
			while (i<N) {
					adr = HashFunc2(adrr,i);
					cout << adr << endl;
				    i++;
					if ((table[adr] == rec) && (status[adr] == 1)) {
						return true;
					}
			}
			return false;
		}


		int AddRecord(Employee rec) {

			bool add_fl = false;
			int add_adr;

			int adrr = HashFunc1(rec);
			int adr = adrr;
			if (status[adr] == 0) {
				table[adr] = rec;
				status[adr] = 1;
				return 0;
			}
			if ((status[adr] == 1) && (rec == table[adr])) {
				return 1;
			}
			int i = 1;
			for (int i = 1; i < N; i++) {
				adr = HashFunc2(adrr,i);
				if ((status[adr] == 1) && (table[adr] == rec)) {
					return 1;                       //����� ������ ��� ����
				}
				if (status[adr] == 0) {
					table[adr] = rec;               //��������
					status[adr] = 1;
					return 0;
				}
			}	                                    //��� �����
		return 2;
		}

		//����������, ���� ���� �������� ������ ��� ��������
		void rehash(int adr, int i) {               
			int adrr = adr;
			adr = HashFunc2(adrr, i);
			while ((i < N) && (status[adr] == 1)) {
				if (status[adr] == 1) {
					table[adrr] = table[adr];
					status[adrr] = 1;
					status[adr] = 0;
					adrr = adr;
					adr = HashFunc2(adrr, i);
				}
				break;
			}
		}

		int DelRecord(Employee rec) {
			int adrr = HashFunc1(rec);
			int adr = adrr;
			if ((rec == table[adr]) && (status[adr] == 1)) {
				status[adr] = 0;                                  //������� 
				rehash(adr, 1);
				return 1;
			}
			else {
				int i = 1;
				adr = HashFunc2(adrr,i);
				i++;
				while (i<N) {
					if ((table[adr] == rec) && (status[adr] == 1)) {
						status[adr] = 0;                           //�������
						rehash(adr, i);
						return 1;
					}
					else {                                        //� 2 ������, ����� ������ ���
						adr = HashFunc2(adrr, i);
						i++;
					}
					if (i > N) {
						return 0;
					}
				}
				return 0;
			}
		}
			

};
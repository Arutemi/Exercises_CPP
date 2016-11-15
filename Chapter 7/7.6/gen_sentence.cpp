#include <vector>
#include <string>
#include <map>
#include <iostream>
#include "split.h"
#include <stdexcept>
#include "nrand.h"
#include "gen_sentence.h"


using std::string;	using std::vector; using std::map;

#define START_RULE "<sentence>"

//�������� ���������� �� �������� ������
Grammar read_grammar(std::istream& in) {
	Grammar ret;
	string line;
    // �������� � ������ ����������
	// ��������� ��������� �������
	while (std::getline(in, line)) {
        // ��������� ��������� ������ �� �����
		vector<string> entry = split(line);
		if (!entry.empty()) {
			//��������� ������� � ��� Grammar
			ret[entry[0]].push_back(Rule(entry.begin() + 1, entry.end()));
		}
	}
	return ret;
};

//��������������� ������� ��� ������ � ��������� <�����������>
vector<string> gen_sentence(const Grammar& g) {

	vector<string> ret;
	gen_aux(g, START_RULE, ret);
	return ret;
};

bool bracketed(const string& s) {

	return s.size() > 1 && s[0] == '<' && s[s.size() - 1] == '>';
};

//������� ������ �� ������� ���������� ����������� �����

void gen_aux(const Grammar& g, const string& word, vector<string>& ret) {

	vector<string> stack_vec.push_back(word);
	string temp;
	while (!stack_vec.empty()) {
        // �������� �� ������� ��������� ������� � ������� ���
        temp = stack_vec.back();
        stack_vec.pop_back();
        if (!bracketed(temp))
            stack_vec.push_back(temp);
        else
        {
            //���� �������������� ������� ��� �������� word
            Grammar::const_iterator it = g.find(word);
            if (it == g.end())
			throw std::logic_error("������ �������");
            //��������� ����� ��������� ������
            const Rule_collection& c = it->second;
            //�� ������� �������� �������� ����
            const Rule& r = c[nrand(c.size())];
            Rule::const_reverse_iterator iter;
            // ���������� ��������� ������� � ���� � �������� �������,
            // �.�. ������ � ��������� ����� ���������� � �����.
            for (iter = r.rbegin(); r != r.rend(); ++iter)
            {
                stack_vec.push_back(*iter);
            }
        }
    }


}





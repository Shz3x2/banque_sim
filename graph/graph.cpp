#include "header.h"
#include "macro.h"


/*int error_handling(const int ac, const char *argv[])
{

}*/

double min(vector<double> tab)
{
    double min = tab[0];

    for (size_t i = 0; i < tab.size(); i++)
        if (tab[i] < min)
            min = tab[i];
    return min;
}

double max(vector<double> tab)
{
    double max = tab[0];

    for (size_t i = 0; i < tab.size(); i++)
        if (tab[i] > max)
            max = tab[i];
    return max;
}

void graph(vector<double> x_values, vector<double> y_values, string x_name, string y_name)
{
    if (x_values.size() != y_values.size())
        return;

    size_t size = x_values.size();
    ifstream ifiles("templates.txt");
    double max_values[2] = {max(x_values), max(y_values)};
    double min_values[2] = {min(x_values), min(y_values)};
    int x_index[10] = {7,21,35,49,63,77,91,105,119,133};
    int y_index[7] = {2,5,8,11,14,17,20};
    vector<string> lines(GRAPH_HEIGHT + 1);

    for (int i = 0; !getline(ifiles, lines[i]); i++);

    lines.shrink_to_fit();
    lines[0] = y_name;
    lines[size - 1] += x_name;

    // Insert y_values index in the graph
    cout << margin[1] << "  " << margin[1] / 5;
    double tmp = 0;
    for (int i = 2; i <= 20; i += 3) {
        lines[i] = to_string(max_values[1] - max_values[1] * tmp) + " " + lines[i];
        tmp += margin[1] / 6;
    }

    for (int i = 0; i < GRAPH_HEIGHT; i++)
        cout << lines[i] << '\n';
}

int main()
{
    vector<double> x(30);
    vector<double> y(30);

    x[0] = 1;
    y[0] = 54.3;

    for (int i = 1; i < 30; i++) {
        x[i] = i + 1;
        y[i] = y[i - 1] * 1.12;
    }
    graph(x, y, "Date (j)", "Tune (€)");
    return 0;
}
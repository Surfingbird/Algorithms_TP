//
// Created by Андрей on 10.12.18.
//

#ifndef SHORTWAY_SEARCH_WAY_H
#define SHORTWAY_SEARCH_WAY_H

#include "ShortWayGraph.h"
#include "queue"

size_t search_way(size_t search_from, size_t search_to, ShortWayGraph &graph) {
    std::queue<GraphPoint*> queue;

    GraphPoint* current = nullptr;
    graph.GetPoint(search_from, current);

    queue.push(current);
    queue.push(nullptr);

    size_t step = 0;
    size_t result = 0;

    while (!queue.empty()) {
        current = queue.front();
        queue.pop();

        if (nullptr == current && queue.size() > 0 && result == 0) {
            queue.push(nullptr); /// вот тут по аккуратней
        }
        if (nullptr == current) {
            ++step;
            continue;
        }

        if(search_to == current->point_number) { /// появиля путь до точки !!! поправить
            ++result;
            continue;
        }

        if (0 == result) {
            current->colour = "black";
            current->length = step; /// растояние от начала к узлу

            std::vector<GraphPoint*> out_edges;
            graph.GetNextVertices(current->point_number, out_edges); /// вот это мне не понравилось

            for (auto i = out_edges.begin(); i != out_edges.end(); ++i) {

                if ("black" == (*i)->colour || "grey" == (*i)->colour) continue; /// уже посещенная вершина
//                if (current->length == (*i)->length) continue;

                if ((*i)->length == 0 || (*i)->length == step + 1) {
                    (*i)->length = step + 1;
                    queue.push(*i);
                }
            }
        }
    }


    return result;
}

#endif //SHORTWAY_SEARCH_WAY_H

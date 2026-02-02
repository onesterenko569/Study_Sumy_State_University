#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int u, v;
    int w;
} Edge;

typedef struct {
    int parent;
    int rank;
} Subset;

/* Порівняльник для qsort — сортуємо ребра за вагою (зростання) */
int edge_cmp(const void* a, const void* b) {
    Edge* ea = (Edge*)a;
    Edge* eb = (Edge*)b;
    return ea->w - eb->w;
}

/* FIND з Path Compression */
int find_set(Subset subsets[], int x) {
    if (subsets[x].parent != x)
        subsets[x].parent = find_set(subsets, subsets[x].parent);
    return subsets[x].parent;
}

/* UNION by Rank */
void union_set(Subset subsets[], int x, int y) {
    int rx = find_set(subsets, x);
    int ry = find_set(subsets, y);

    if (rx == ry) return;

    if (subsets[rx].rank < subsets[ry].rank) {
        subsets[rx].parent = ry;
    }
    else if (subsets[rx].rank > subsets[ry].rank) {
        subsets[ry].parent = rx;
    }
    else {
        subsets[ry].parent = rx;
        subsets[rx].rank++;
    }
}

/* Крускал */
void kruskal(Edge edges[], int E, int V) {
    qsort(edges, E, sizeof(Edge), edge_cmp);

    Subset* subsets = (Subset*)malloc((V + 1) * sizeof(Subset));
    if (!subsets) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }

    for (int i = 1; i <= V; i++) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }

    Edge* mst = (Edge*)malloc((V - 1) * sizeof(Edge));
    if (!mst) {
        fprintf(stderr, "Memory allocation failed\n");
        free(subsets);
        return;
    }

    int e = 0; /* кількість вибраних ребер в MST */
    int i = 0; /* індекс перегляду ребер (впорядковані) */
    long long mst_weight = 0;

    while (e < V - 1 && i < E) {
        Edge next = edges[i++];

        int x = find_set(subsets, next.u);
        int y = find_set(subsets, next.v);

        if (x != y) {
            mst[e++] = next;
            mst_weight += next.w;
            union_set(subsets, x, y);
        }
    }

    if (e != V - 1) {
        printf("Граф не зв'язний — MST не існує (вибрано %d ребер)\n", e);
    }
    else {
        printf("MST знайдено. Загальна вага = %lld\n", mst_weight);
        printf("Ребра MST (u v w):\n");
        for (int j = 0; j < e; j++) {
            printf("%d %d %d\n", mst[j].u, mst[j].v, mst[j].w);
        }
    }

    free(subsets);
    free(mst);
}

int main() {
    int V, E;
    /* Формат вводу:
       V E
       потім E рядків: u v w
       Вершини нумеруються від 1 до V (якщо у вас інша нумерація — поправте) */
    if (scanf_s("%d %d", &V, &E) != 2) {
        fprintf(stderr, "Неправильний формат вводу\n");
        return 1;
    }

    Edge* edges = (Edge*)malloc(E * sizeof(Edge));
    if (!edges) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < E; i++) {
        int u, v, w;
        if (scanf_s("%d %d %d", &u, &v, &w) != 3) {
            fprintf(stderr, "Неправильний формат ребра на рядку %d\n", i + 1);
            free(edges);
            return 1;
        }
        edges[i].u = u;
        edges[i].v = v;
        edges[i].w = w;
    }

    kruskal(edges, E, V);

    free(edges);
    return 0;
}

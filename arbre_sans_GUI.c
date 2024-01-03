#include <stdio.h>
#include <stdlib.h>

// Définition d'une structure pour les nœuds de l'arbre binaire
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Fonction pour créer un nouveau nœud
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Fonction pour insérer un nœud dans l'arbre
struct Node* insertNode(struct Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insertNode(root->left, value);
    } else if (value > root->data) {
        root->right = insertNode(root->right, value);
    }

    return root;
}

// Fonction pour parcourir l'arbre en ordre croissant (inorder)
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main() {
    // Initialiser la racine de l'arbre à NULL
    struct Node* root = NULL;

    // Remplir l'arbre avec les valeurs de 1 à 10
    for (int i = 1; i <= 10; i++) {
        root = insertNode(root, i);
    }

    // Afficher le parcours inorder de l'arbre
    printf("Parcours Inorder de l'arbre : ");
    inorderTraversal(root);
    printf("\n");

    // Libérer la mémoire en libérant les nœuds de l'arbre (peut être ajouté à la fin du programme)
    // À faire après avoir utilisé l'arbre pour éviter les fuites de mémoire
    // freeTree(root);

    return 0;
}

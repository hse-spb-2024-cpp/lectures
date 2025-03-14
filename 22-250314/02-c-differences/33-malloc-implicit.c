int main(void) {
    int *a = malloc(sizeof(int));  // TODO: reproduce?
    a[0] = 10;
    printf("%p %d\n", a, a[0]);
    free(a);
}

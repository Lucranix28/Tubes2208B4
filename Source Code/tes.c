void f(char *s)
{
    printf("---%*s%*s---\n", 10 + strlen(s) / 2, s, 10 - strlen(s) / 2, "");
}
int main(int argc, char **argv)
{
    f("uno");
    f("quattro");
    return 0;
}
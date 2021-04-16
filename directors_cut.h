#ifndef DIRECTORS_CUT_H
#define DIRECTORS_CUT_H

/* =======================Prototypes======================= */
/* directors_cut1.c */
void setenv_part2(char **, int *, char *, char **, char **, char **);
void unsetenv_p2(char **a_error, char ***o_en);
void unsetenv_p3(char **a_error, char ***o_en);
void cd_p2(char c, char **path, char *av1, char ***env);
void cd_p3(char ***o_en, char **path);

/* directors_cut2.c */
void sytx_man_p2(int fd, char ***o_en, char ***cmd_split, char **cmmd);
void sytx_man_p3(int fd, char ***o_en);
int extrn_cmd_2(char **baby_av, int *bool, struct stat *st,
char **aux, char **aux2, char ***o_en, char ***env);
void extrn_cmd_3(char **aux, char ***o_en);

/*==========================================================*/

#endif /* DIRECTORS_CUT_H */

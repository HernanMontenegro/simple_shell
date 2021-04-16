#ifndef DIRECTORS_CUT_H
#define DIRECTORS_CUT_H

/* =======================Prototypes======================= */
/* directors_cut1.c */
void setenv_part2(char **, int *, char *, char **, char **, char **);
void unsetenv_p2(char **a_error, char ***o_en);
void unsetenv_p3(char **a_error, char ***o_en);
void cd_p2(char c, char **path, char *av1, char ***env);
void cd_p3(char ***o_en, char **path);


/*==========================================================*/

#endif /* DIRECTORS_CUT_H */
#include "uls.h"

t_file *mx_create_file(char *path)
{
    t_file *file = mx_memalloc(sizeof(t_file));
	t_stat stat;

	lstat(path, &stat);
	file->name = mx_strdup(path);
	file->st_mode = stat.st_mode;
	file->st_nlink = stat.st_nlink;
	file->st_uid = stat.st_uid;
	file->st_gid = stat.st_gid;
	file->st_size = stat.st_size;
	file->st_rdev = stat.st_rdev;
	file->st_blocks = stat.st_blocks;
	file->st_atim = stat.st_atimespec;
	file->st_mtim = stat.st_mtimespec;
	file->st_ctim = stat.st_ctimespec;
    return file;
}

void mx_lst_add_file(t_file **list, t_file *file) {
    if (!list || !*list) {
		*list = file;
		return;
	}
	file->next = *list;
    *list = file;
}
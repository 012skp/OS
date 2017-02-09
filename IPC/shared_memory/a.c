#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/shm.h>
#include<sys/stat.h>
#include<sys/ipc.h>

#define ll long long

int main(int argc, char *argv[]){
	int segment_id;
	char *shared_memory;
	int size = 4096;
	segment_id = shmget(IPC_PRIVATE,size,S_IRUSR|S_IWUSR);

	printf("shmid = %d\n",segment_id);
	if(segment_id == -1){ perror("error: "); exit(0);}
	shared_memory = (char*)shmat(segment_id,NULL,0);
	printf(shared_memory,"Hi there...");

	printf("from shared memory:%s at loc %p\n",shared_memory,shared_memory);


	struct shmid_ds buff;
	struct shminfo buff1;
	struct shm_info buff2;
	shmctl(segment_id,IPC_STAT,&buff);

	printf("IPC_PERM: uid = %d, gid = %d, cuid = %d, cgid = %d, mode = %d, __seq = %d\n",
		buff.shm_perm.uid,buff.shm_perm.gid,buff.shm_perm.cuid,buff.shm_perm.cgid,buff.shm_perm.mode,buff.shm_perm.__seq);
	printf("shm_segsz = %d, shm_atime = %d, shm_dtime = %d, shm_ctime = %d, shm_cpid = %d, shm_lpid = %d, shm_nattach = %d\n",
		(int)buff.shm_segsz,(int)buff.shm_atime,(int)buff.shm_dtime,(int)buff.shm_ctime,(int)buff.shm_cpid,(int)buff.shm_lpid,(int)buff.shm_nattch);

/*
	shmctl(segment_id,IPC_INFO,(struct shmid_ds*)&buff1);
	printf("GLOBAL_INFO abt shared memory: shm_max = %lld, shm_min = %lld, shmmni = %lld, shmseg = %lld,shmall = %lld\n",
		(ll)buff1.shmmax,(ll)buff1.shmmin,(ll)buff1.shmmni,(ll)buff1.shmseg,(ll)buff1.shmall);
*/

	shmctl(segment_id,SHM_INFO,(struct shmid_ds*)&buff2);
	printf("SHM_INFO: used_ids = %lld, shm_tot = %lld, shm_rss = %lld, shm_swp = %lld\n",
		(ll)buff2.used_ids,(ll)buff2.shm_tot,(ll)buff2.shm_rss,(ll)buff2.shm_swp);



	shmdt(shared_memory);
	shmctl(segment_id,IPC_RMID,NULL);
return 0;
}

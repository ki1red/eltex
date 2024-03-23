#include <stdio.h>
#include <string.h>

//|---------------------------------------------------------------------------------------------------|
//|Second name*|First name*|Patronymic|Job name|Position held|Number phone|Email|Links to social media|
//|---------------------------------------------------------------------------------------------------|

#define LN 64

typedef struct JobInfo
{
	char job_name[LN];
	char position_held[LN];
}Jobinfo;

typedef struct LinksToSocialMedia
{
	char link_first[LN];
	char link_second[LN];
}Links;

typedef struct UserContact
{
	char second_name[LN];
	char first_name[LN];
	char patronymic[LN];
	Jobinfo job_info;
	char number_phone[LN];
	char email[LN];
	Links social_media;
}Contact; 


void CreateContact(Contact* contact);
void CreateJobinfo(Jobinfo* job_info);
void CreateLinks(Links* social_media);
void DisplayContacts(Contact* contacts, int size);
void DeleteContact(const int num_contact, Contact* contacts, int* size);
void EditContact(Contact* contact);
void EditJobinfo(Jobinfo* job_info);
void EditLinks(Links* links);

void CreateContact(Contact* contact) {
	do {
		fprintf(stdout, "Input the second name *: ");
		fgets(contact->second_name, LN, stdin);
	}while (!strcmp(contact->second_name,"\n"));
	contact->second_name[strcspn(contact->second_name, "\n")] = 0;
	do {
		fprintf(stdout, "Input the first name *: ");
		fgets(contact->first_name, LN, stdin);
	}while (!strcmp(contact->first_name, "\n"));
	contact->first_name[strcspn(contact->first_name, "\n")] = 0;
	fprintf(stdout, "Input the patronymic: ");
	fgets(contact->patronymic, LN, stdin);
	contact->patronymic[strcspn(contact->patronymic, "\n")] = 0;
	CreateJobinfo(&contact->job_info);
	fprintf(stdout, "Input the number phone: ");
	fgets(contact->number_phone, LN, stdin);
	contact->number_phone[strcspn(contact->number_phone, "\n")] = 0;
	fprintf(stdout, "Input the email: ");
	fgets(contact->email, LN, stdin);
	contact->email[strcspn(contact->email, "\n")] = 0;
	CreateLinks(&contact->social_media);
}

void CreateJobinfo(Jobinfo* job_info) {
	fprintf(stdout, "Input the jobname: ");
	fgets(job_info->job_name, LN, stdin);
	job_info->job_name[strcspn(job_info->job_name, "\n")] = 0;
	fprintf(stdout, "Input the position held: ");
	fgets(job_info->position_held, LN, stdin);
	job_info->position_held[strcspn(job_info->position_held, "\n")] = 0;
}

void CreateLinks(Links* social_media) {
	fprintf(stdout, "Input the first link: ");
	fgets(social_media->link_first, LN, stdin);
	social_media->link_first[strcspn(social_media->link_first, "\n")] = 0;
	fprintf(stdout, "Input the second link: ");
	fgets(social_media->link_second, LN, stdin);
	social_media->link_second[strcspn(social_media->link_second, "\n")] = 0;
}

void DisplayContacts(Contact* contacts, const int size) {
	fprintf(stdout, "#\tSecond name*\tFirst name*\tPatronymic\tJob name\tPosition held\tNumber phone\t\tEmail\tLinks to social media\n");
	for (int i = 0; i < size; i++) {
		Contact c = contacts[i];
		Jobinfo j = c.job_info;
		Links l = c.social_media;
		printf("%d\t%10s\t%10s\t%10s\t%10s\t%10s\t%10s\t%10s\t%10s %10s\n",i+1,c.second_name,c.first_name,c.patronymic,j.job_name,j.position_held,c.number_phone,c.email,l.link_first,l.link_second);
	}
}

void DeleteContact(const int num_contact, Contact* contacts, int* size) {
	(*size)--;
	for (int i = num_contact - 1; i < *size; i++) {
		contacts[i] = contacts[i+1];
	}
}

void EditContact(Contact* contact) {
	char text[LN];

	fprintf(stdout, "Input the second name: ");
	fgets(text, LN, stdin);
	if (strcmp(text, "\n")) {
		strcpy(contact->second_name, text);
		contact->second_name[strcspn(contact->second_name, "\n")] = 0;
	}
	fprintf(stdout, "Input the firstname: ");
	fgets(text, LN, stdin);
	if (strcmp(text ,"\n")) {
		strcpy(contact->first_name,text);
		contact->first_name[strcspn(contact->first_name, "\n")] = 0;
	}
	fprintf(stdout, "Input the patronymic: ");
	fgets(text, LN, stdin);
	if (strcmp(text, "\n")) {
		strcpy(contact->patronymic, text);
		contact->patronymic[strcspn(contact->patronymic, "\n")] = 0;
	}
	EditJobinfo(&contact->job_info);
	fprintf(stdout, "Input the number phone: ");
	fgets(text, LN, stdin);
	if (strcmp(text, "\n")) {
		strcpy(contact->number_phone, text);
		contact->number_phone[strcspn(contact->number_phone, "\n")] = 0;
	}
	fprintf(stdout, "Input the email: ");
	fgets(text, LN, stdin);
	if (strcmp(text, "\n")) {
		strcpy(contact->email, text);
		contact->email[strcspn(contact->email, "\n")] = 0;
	}
	EditLinks(&contact->social_media);
}

void EditJobinfo(Jobinfo* job_info) {
	char text[LN];

	fprintf(stdout, "Input the jobname: ");
	fgets(text, LN, stdin);
	if (strcmp(text, "\n")) {
		strcpy(job_info->job_name, text);
		job_info->job_name[strcspn(job_info->job_name, "\n")] = 0;
	}
	fprintf(stdout, "Input the position held: ");
	fgets(text, LN, stdin);
	if (strcmp(text, "\n")) {
		strcpy(job_info->position_held, text);
		job_info->position_held[strcspn(job_info->position_held, "\n")] = 0;
	}
}

void EditLinks(Links* links) {
	char text[LN];

	fprintf(stdout, "Input the first link: ");
	fgets(text, LN, stdin);
	if (strcmp(text, "\n")) {
		strcpy(links->link_first, text);
		links->link_first[strcspn(links->link_first, "\n")] = 0;
	}
	fprintf(stdout, "Input the second link: ");
	fgets(text, LN, stdin);
	if (strcmp(text, "\n")) {
		strcpy(links->link_second, text);
		links->link_second[strcspn(links->link_second, "\n")] = 0;
	}
}

int main(void) {
	char* menu[] = {"\np - display contacts", "c - create new contact", "e - edit old contact", "r - remove old contact", "esc - exit"};
	int k = sizeof(menu)/sizeof(menu[0]);
	Contact contacts[10];
	int size = 0;
	char choose[LN];
	do {
		int i;
		for (i = 0; i < k; i++)
			fprintf(stdout, "%s\n", menu[i]);
		fgets(choose, LN, stdin);
		switch (choose[0])
		{
		case 'c':
			CreateContact(&contacts[size]);
			size++;
			break;
		case 'r':
			fprintf(stdout, "\nInput the num element: ");
			if (scanf("%d%c", &i, &choose[0]) && i > 0 && i <= size)
				DeleteContact(i, contacts, &size);
			else
				fprintf(stdout, "Num is not correct");
			break;
		case 'e':
			fprintf(stdout, "\nInput the num element: ");
			if (scanf("%d%c", &i, &choose[0]) && i > 0 && i <= size)
				EditContact(&contacts[--i]);
			else
				fprintf(stdout, "Num is not correct");
			break;
		case 'p':
			DisplayContacts(contacts, size);
		default:
			break;
		}
		
	}while(choose[0] != 27);
	return 0;
}
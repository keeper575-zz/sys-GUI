#include <gtk-3.0/gtk/gtk.h>
void main (int argc, char *argv[])
{
int i=0;
gtk_init (&argc, &argv);
GtkWidget *hello = gtk_message_dialog_new (NULL, GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_OK, "Temp");
system("sensors |grep 'temp1'|awk '{print $2}' > temp.txt");
FILE *fd = fopen("temp.txt","r");
char msg[6];
int c;
//fgets(msg,3,fd);
while(i<5)
	{
	c= fgetc(fd);
	msg[i] = c;
	//fd++;
	i++;
	}
msg[i] = '\0';
gtk_message_dialog_format_secondary_text (GTK_MESSAGE_DIALOG (hello),msg);
gtk_dialog_run(GTK_DIALOG (hello));
}

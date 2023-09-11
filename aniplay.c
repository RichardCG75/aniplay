#include <gtk/gtk.h>

#define G_APPLICATION_DEFAULT_FLAGS 0

static void log_message (GtkWidget *widget, gpointer data)
{
  g_print ("Button clicked\n");
}

static void activate (GtkApplication *app, gpointer user_data)
{
  GtkWidget *window;
  GtkWidget *button;

  window = gtk_application_window_new (app);
  gtk_window_set_title (GTK_WINDOW (window), "AniPlayer");
  gtk_window_set_default_size (GTK_WINDOW (window), 800, 400);

  button = gtk_button_new_with_label ("Click here");
  g_signal_connect (button, "clicked", G_CALLBACK (log_message), NULL);
  gtk_window_set_child (GTK_WINDOW (window), button);

  gtk_window_present (GTK_WINDOW (window));
}

int main (int argc, char **argv)
{
  GtkApplication *app;
  int status;

  app = gtk_application_new ("org.gtk.example", G_APPLICATION_DEFAULT_FLAGS);
  g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
  status = g_application_run (G_APPLICATION (app), argc, argv);
  g_object_unref (app);

  return status;
}

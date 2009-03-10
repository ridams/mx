#include <stdio.h>
#include <stdlib.h>

#include <clutter/clutter.h>
#include <nbtk/nbtk.h>

void
button_clicked_cb (NbtkButton *button, gchar *name)
{
  printf ("%s button clicked!\n", name);
}

int
main (int argc, char *argv[])
{
  NbtkWidget *button;
  ClutterColor stage_color =  { 0xff, 0xff, 0xff, 0xff };
  NbtkPadding padding = { 0, };
  ClutterActor *stage;

  clutter_init (&argc, &argv);

  /* load the style sheet */
  nbtk_style_load_from_file (nbtk_style_get_default (),
                             "style/default.css", NULL);

  padding.left = CLUTTER_UNITS_FROM_DEVICE (40);
  padding.right = CLUTTER_UNITS_FROM_DEVICE (40);
  padding.top = CLUTTER_UNITS_FROM_DEVICE (40);
  padding.bottom = CLUTTER_UNITS_FROM_DEVICE (40);

  stage = clutter_stage_get_default ();
  clutter_stage_set_color (CLUTTER_STAGE (stage), &stage_color);

  button = nbtk_button_new_with_label ("Hello World!");
  g_signal_connect (button, "clicked",
                    G_CALLBACK (button_clicked_cb),
                    "hello");
  nbtk_button_set_tooltip (NBTK_BUTTON (button), "Hola Mundo!");
  g_object_set (button, "transition-duration", 400,
                "transition-type", NBTK_TRANSITION_FADE, NULL);
  clutter_container_add_actor (CLUTTER_CONTAINER (stage),
                               CLUTTER_ACTOR (button));
  clutter_actor_set_position (CLUTTER_ACTOR (button), 100, 100);
  nbtk_widget_set_padding (NBTK_WIDGET (button), &padding);

  button = nbtk_button_new ();
  clutter_actor_set_name (CLUTTER_ACTOR (button), "style-button");
  g_signal_connect (button, "clicked",
                    G_CALLBACK (button_clicked_cb),
                    "icon");
  nbtk_button_set_icon_from_file (NBTK_BUTTON (button),
                                  "redhand.png");
  g_object_set (button, "transition-duration", 400,
                "transition-type", NBTK_TRANSITION_BOUNCE, NULL);
  clutter_container_add_actor (CLUTTER_CONTAINER (stage),
                               CLUTTER_ACTOR (button));
  clutter_actor_set_position (CLUTTER_ACTOR (button), 300, 100);
  nbtk_widget_set_padding (NBTK_WIDGET (button), &padding);

  button = nbtk_button_new_with_label ("Toggle");
  g_signal_connect (button, "clicked",
                    G_CALLBACK (button_clicked_cb),
                    "toggle");
  nbtk_button_set_toggle_mode (NBTK_BUTTON (button), TRUE);
  clutter_container_add_actor (CLUTTER_CONTAINER (stage),
                               CLUTTER_ACTOR (button));
  clutter_actor_set_position (CLUTTER_ACTOR (button), 100, 200);
  nbtk_widget_set_padding (NBTK_WIDGET (button), &padding);

  button = nbtk_button_new ();
  g_signal_connect (button, "clicked",
                    G_CALLBACK (button_clicked_cb),
                    "style");
  clutter_actor_set_name (CLUTTER_ACTOR (button), "style-button");
  clutter_container_add_actor (CLUTTER_CONTAINER (stage),
                               CLUTTER_ACTOR (button));
  clutter_actor_set_position (CLUTTER_ACTOR (button), 100, 300);
  clutter_actor_set_size (CLUTTER_ACTOR (button), 100, 100);

  clutter_actor_show (stage);

  clutter_main ();

  return EXIT_SUCCESS;
}

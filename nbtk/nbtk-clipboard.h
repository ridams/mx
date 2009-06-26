/* nbtk-clipboard.h */

#ifndef _NBTK_CLIPBOARD_H
#define _NBTK_CLIPBOARD_H

#include <glib-object.h>

G_BEGIN_DECLS

#define NBTK_TYPE_CLIPBOARD nbtk_clipboard_get_type()

#define NBTK_CLIPBOARD(obj) \
  (G_TYPE_CHECK_INSTANCE_CAST ((obj), \
  NBTK_TYPE_CLIPBOARD, NbtkClipboard))

#define NBTK_CLIPBOARD_CLASS(klass) \
  (G_TYPE_CHECK_CLASS_CAST ((klass), \
  NBTK_TYPE_CLIPBOARD, NbtkClipboardClass))

#define NBTK_IS_CLIPBOARD(obj) \
  (G_TYPE_CHECK_INSTANCE_TYPE ((obj), \
  NBTK_TYPE_CLIPBOARD))

#define NBTK_IS_CLIPBOARD_CLASS(klass) \
  (G_TYPE_CHECK_CLASS_TYPE ((klass), \
  NBTK_TYPE_CLIPBOARD))

#define NBTK_CLIPBOARD_GET_CLASS(obj) \
  (G_TYPE_INSTANCE_GET_CLASS ((obj), \
  NBTK_TYPE_CLIPBOARD, NbtkClipboardClass))

typedef struct _NbtkClipboard NbtkClipboard;
typedef struct _NbtkClipboardClass NbtkClipboardClass;
typedef struct _NbtkClipboardPrivate NbtkClipboardPrivate;

/**
 * NbtkClipboard:
 *
 * The contents of this structure is private and should only be accessed using
 * the provided API.
 */
struct _NbtkClipboard
{
  /*< private >*/
  GObject parent;
  NbtkClipboardPrivate *priv;
};

struct _NbtkClipboardClass
{
  GObjectClass parent_class;
};

/**
 * NbtkClipboardCallbackFunc:
 * @clipboard: A #NbtkClipboard
 * @text: text from the clipboard
 * @user_data: user data
 *
 * Callback function called when text is retrieved from the clipboard.
 */
typedef void (*NbtkClipboardCallbackFunc) (NbtkClipboard *clipboard,
                                           const gchar   *text,
                                           gpointer       user_data);

GType nbtk_clipboard_get_type (void);

NbtkClipboard* nbtk_clipboard_get_default ();
void nbtk_clipboard_get_text (NbtkClipboard *clipboard, NbtkClipboardCallbackFunc callback, gpointer user_data);
void nbtk_clipboard_set_text (NbtkClipboard *clipboard, const gchar *text);

G_END_DECLS

#endif /* _NBTK_CLIPBOARD_H */

// TUI rendering API
#ifndef UI_H
#define UI_H

void ui_init(void);
void ui_render_log(const char *msg);
void ui_render_log_a(const char *msg, const char *arg);
void ui_render_error(const char *err);
int ui_getinput(void);
void ui_cleanup(void);

#endif // !UI_H

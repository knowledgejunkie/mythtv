#ifndef DIALOGBOX_H_
#define DIALOGBOX_H_

#include "mythwidgets.h"
#include "xmlparse.h"

class QVBoxLayout;
class QButtonGroup;
class QString;
class QCheckBox;

class DialogBox : public MythDialog
{
    Q_OBJECT
  public:
    DialogBox(const QString &text, const char *checkboxtext = 0,
              QWidget *parent = 0, const char *name = 0);

    void AddButton(const QString &title);

    bool getCheckBoxState(void) {  if (checkbox) return checkbox->isChecked();
                                   return false; }
  protected slots:
    void buttonPressed(int which);

  private:
    QVBoxLayout *box;
    QButtonGroup *buttongroup;

    QCheckBox *checkbox;
};

class MythThemedDialog : public MythDialog
{
//    Q_OBJECT

    //
    //  A potential base class for Myth GUI screens that are built
    //  from ui.xml files
    //
    
  public:
  
    //
    //  Constructor needs the name of "this" window (the one to be 
    //  themed) and possibly a filename where the theme is
    //
      
    MythThemedDialog(QString window_name, QString theme_filename = "",
                     QWidget *parent = 0, const char *name = 0);


    virtual void loadWindow(QDomElement &);
    virtual void parseContainer(QDomElement &);
    virtual void parseFont(QDomElement &);
    virtual void parsePopup(QDomElement &);
    virtual void updateBackground();
    
    UIType* getUIObject(QString name);
    
    void setContext(int a_context){context = a_context;}
    
  protected:
  
    virtual void paintEvent(QPaintEvent* e);
    
  private:
  
    XMLParse    *theme;
    QDomElement xmldata;                     
    QPixmap     my_background;
    int         context;
    
    QPtrList<LayerSet>  my_containers;
};

#endif

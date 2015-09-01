#ifndef _LOGINDLG_H_
#define _LOGINDLG_H_
#include "gui/XWindow.h"
#include "gui/XTextField.h"
#include "gui/XButton.h"
#include "gui/XPassworldField.h"
#include "Game.h"

namespace modou
{
    class LoginDlg : public XWindow,
                     public gcn::ActionListener
    {
        public:
            LoginDlg();
            virtual ~LoginDlg();

            void close();
            void place(int row, int clo, gcn::Widget *widget);
            void action(const gcn::ActionEvent &event);
        private:
            XTextField *mUserField;
            XPassworldField *mPassField;
            XButton *mLoginBtn;
            XButton *mCancelBtn;
            Game *mGame;
            int mRowHeight;
            int mCellWidth;
            int mRowNum;
            int mColNum;
    };
}

#endif

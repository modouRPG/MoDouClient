#include "LoginDlg.h"
#include "net/pkg.h"
#include <string.h>
#include "main.h"
#include "gui/WorldSelectDlg.h"

namespace modou
{
    LoginDlg::LoginDlg() :
        XWindow("登录"),
        gcn::ActionListener(),
        mUserField(new XTextField()),
        mPassField(new XPassworldField()),
        mLoginBtn(new XButton("登录", "login", this)),
        mCancelBtn(new XButton("注册", "register", this)),
        mRowNum(4),
        mColNum(2)
    {
        setSize(250,120);

        gcn::Label *mUserLabel = new gcn::Label("邮箱：");
        gcn::Label *mPassLabel = new gcn::Label("密码：");

        mRowHeight = mUserField->getHeight() + 4;
        mCellWidth = this->getWidth() / mColNum;
        
        place(0, 0, mUserLabel);
        place(0, 1, mUserField);
        place(1, 0, mPassLabel);
        place(1, 1, mPassField);
        place(2, 0, mLoginBtn);
        place(2, 1, mCancelBtn);
        //this->add(mUserLabel, 0, 0);
        //this->add(mUserField, mUserLabel->getWidth(), 0);
        //this->add(mPassLabel, 0, mUserLabel->getHeight());
        //this->add(mPassField, mPassLabel->getWidth(), mUserLabel->getHeight());

        //this->add(mLoginBtn);
        //this->add(mCancelBtn);
        setVisible(true);
    }

    LoginDlg::~LoginDlg()
    {
    
    }

    void LoginDlg::action(const gcn::ActionEvent &event)
    {
        const std::string &eventId = event.getId();
        if (eventId == "login") {
            std::string u = mUserField->getText();
            std::string p = mPassField->getText();
            login_req_pkg pkg;
            memset(&pkg, 0, sizeof(pkg));
            pkg.flag = LOGIN_FLAG;
            strcpy(pkg.email, u.c_str());
            strcpy(pkg.pass, p.c_str());
            globals::loginConn->Send(&pkg);
	    //gcn::Container *const top = static_cast<gcn::Container *>(globals::gui->getTop());
	    //WorldSelectDlg *wsDlg = new WorldSelectDlg();
	    //top->remove(this);
	    //top->add(wsDlg, (top->getWidth() - this->getWidth()) / 2, (top->getHeight() - this->getHeight())/2);
	    mGame = new Game();
        } else if (eventId == "register") {

        }
    }

    void LoginDlg::place(int row, int col, gcn::Widget *widget)
    {
        // 偶数列左对齐，奇数列右对齐
        if (col % 2 == 0) {
            this->add(widget, (col + 1) * mCellWidth - widget->getWidth() - 10, row * mRowHeight + (this->getHeight() - mRowNum * mRowHeight) / 2);
        } else {
            this->add(widget, col * mCellWidth, row * mRowHeight + (this->getHeight() - mRowNum * mRowHeight) / 2);
        }
    }

    void LoginDlg::close()
    {
        close();
    }
}

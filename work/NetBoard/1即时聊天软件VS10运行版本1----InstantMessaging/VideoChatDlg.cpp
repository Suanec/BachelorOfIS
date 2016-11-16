// VideoChatDlg.cpp : implementation file
//

#include "stdafx.h"
#include "instantmessaging.h"
#include "VideoChatDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#include "InstantMessagingDlg.h"
#include "Debug.h"

/////////////////////////////////////////////////////////////////////////////
// CVideoChatDlg dialog


CVideoChatDlg::CVideoChatDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CVideoChatDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CVideoChatDlg)
	//}}AFX_DATA_INIT

	m_bReceiveAudio			= FALSE;
	m_bRecord				= FALSE;
	m_bPlaying				= FALSE;
	m_bReceiveFinished		= TRUE;
	m_pAudioData			= NULL;
}


void CVideoChatDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CVideoChatDlg)
	DDX_Control(pDX, IDS_SELF, m_staticSelf);
	DDX_Control(pDX, IDS_FRIEND, m_staticFriend);
	DDX_Control(pDX, IDC_TRUMP, m_btnTrump);
	DDX_Control(pDX, IDC_MIKE, m_btnMike);
	DDX_Control(pDX, IDB_SETTING, m_btnSetting);
	DDX_Control(pDX, IDB_SELF, m_btnSelf);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CVideoChatDlg, CDialog)
	//{{AFX_MSG_MAP(CVideoChatDlg)
	ON_BN_CLICKED(IDOK, OnOk)
	ON_BN_CLICKED(IDB_SETTING, OnSetting)
	ON_BN_CLICKED(IDB_SELF, OnSelf)
	ON_WM_LBUTTONDOWN()
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_MIKE, OnMike)
	ON_BN_CLICKED(IDC_TRUMP, OnTrump)
	ON_MESSAGE( MM_WOM_OPEN, WaveOutOpenL )
	ON_MESSAGE( MM_WOM_DONE, WaveOutDoneL )
	ON_MESSAGE( MM_WOM_CLOSE, WaveOutCloseL )
	ON_WM_ERASEBKGND()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CVideoChatDlg message handlers

void CVideoChatDlg::OnOk() 
{
}

void CVideoChatDlg::OnCancel() 
{	
	if( IDOK == MessageBox( "要关闭视频聊天吗？", "关闭", MB_OKCANCEL | MB_ICONINFORMATION | MB_DEFBUTTON2 ) )
	{
		/// 调用主对话框的函数
		m_pMainDlg->CloseVideoChatDlg( m_userChat );
	
		/// 恢复初始值
		m_bReceiveAudio			= FALSE;
		m_bRecord				= FALSE;
		m_bPlaying				= FALSE;

		/// 删除内存dc和bitmap
		m_bitmap.DeleteObject();
		m_dcMem.DeleteDC();

		/// 删除申请的内存
		for( int nIndex = 0; nIndex < m_arrAudioBuffer.GetSize(); nIndex++ )
		{
			char *pAudioBuffer = m_arrAudioBuffer.GetAt( nIndex );
			delete [] pAudioBuffer;
			m_arrAudioBuffer.RemoveAt( nIndex );
			nIndex--;
		}
		waveOutPause( m_hWaveOut );
		waveOutUnprepareHeader( m_hWaveOut, m_pWaveHdr1, sizeof ( WAVEHDR ) ) ;
		waveOutClose( m_hWaveOut ) ;
		delete [] m_pWaveHdr1;

		/// 删除保存的视频数据
		m_lstVideoData.RemoveAll();
		
		m_VideoChatSocket.Close();
		
		if( !m_pAudioData )
		{
			delete [] m_pAudioData;
			m_pAudioData = NULL;
		}

		DestroyWindow();
		delete this;
	}
}

BOOL CVideoChatDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	/// 初始化窗口
	Init();	

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

/// 初始化窗口
void CVideoChatDlg::Init()
{
	/// 获取主对话框
	m_pMainDlg = ( CInstantMessagingDlg * )::AfxGetMainWnd();

	/// 设置视频窗口的大小
	m_staticFriend.SetWindowPos( NULL, 0, 0, VIDEOCHAT_VIDEOWND_WIDTH, VIDEOCHAT_VIDEOWND_HEIGHT,
		SWP_NOMOVE | SWP_NOZORDER );
	m_staticSelf.SetWindowPos( NULL, 0, 0, VIDEOCHAT_VIDEOWND_WIDTH, VIDEOCHAT_VIDEOWND_HEIGHT,
		SWP_NOMOVE | SWP_NOZORDER );

	/// 没有连接上视频聊天对象
	m_bConnect	= FALSE;
	m_bDeny		= FALSE;

	/// 创建内存dc
	CDC *pDC = m_staticFriend.GetDC();
	CRect rectFriend;
	m_staticFriend.GetClientRect( &rectFriend );
	m_dcMem.CreateCompatibleDC( pDC );
	m_bitmap.CreateCompatibleBitmap( pDC, rectFriend.Width(), rectFriend.Height() );
	m_dcMem.SelectObject( &m_bitmap );
	m_dcMem.FillSolidRect( rectFriend, RGB( 128, 128, 128 ) );
	ReleaseDC( pDC );

	/// 初始化声音
	m_WaveForm.wFormatTag		= WAVE_FORMAT_PCM;
	m_WaveForm.nChannels		= 1;
	m_WaveForm.nSamplesPerSec	= 11025;
	m_WaveForm.nAvgBytesPerSec	= 11025;
	m_WaveForm.nBlockAlign		= 1;
	m_WaveForm.wBitsPerSample	= 8;
	m_WaveForm.cbSize			= 0;
	waveOutOpen( &m_hWaveOut, WAVE_MAPPER, &m_WaveForm, ( DWORD )m_hWnd, 0, CALLBACK_WINDOW );

	m_pWaveHdr1 = ( PWAVEHDR )new char[ sizeof( WAVEHDR ) ];
	m_pWaveHdr1->dwBufferLength  = AUDIO_BUFFER_SIZE;
	m_pWaveHdr1->dwBytesRecorded = 0;
	m_pWaveHdr1->dwUser          = 0;
	m_pWaveHdr1->dwFlags         = WHDR_BEGINLOOP | WHDR_ENDLOOP;
	m_pWaveHdr1->dwLoops         = 1;
	m_pWaveHdr1->lpNext          = NULL;
	m_pWaveHdr1->reserved        = 0;

	/// 申请音频数据的缓冲区
	for( int nIndex = 0; nIndex < AUDIO_BUFFER_BLOCK; nIndex++ )
	{
		char *pAudioBuffer = new char[ AUDIO_BUFFER_SIZE + sizeof( DWORD ) ];
		m_arrAudioBuffer.Add( pAudioBuffer );
	}
	m_nReceive	= 0;
	m_nPlay		= 0;

	/// 初始化
	m_dwRecordAudioTickTime	= 0;
	m_dwPlayAudioTickTime	= 0;

	/// 设置timer
	SetTimer( TIMER_VIDEOCHAT, DEFALUT_VIDEOCHAT_REFRESH, NULL );
}

/// 设置聊天的对象
void CVideoChatDlg::SetChatUser( const USER userChat )
{
	memcpy( &m_userChat, &userChat, sizeof( USER ) );
	
	/// 设置标题
	CString strTitle;
	strTitle.Format( "视频聊天 - %s", m_userChat.strName );
	SetWindowText( strTitle );
}

void CVideoChatDlg::OnLButtonDown(UINT nFlags, CPoint point) 
{
	PostMessage( WM_NCLBUTTONDOWN, HTCAPTION, MAKELPARAM( point.x, point.y ) );	
	CDialog::OnLButtonDown(nFlags, point);
}

void CVideoChatDlg::OnSetting() 
{
	CString strText;
	m_btnSetting.GetWindowText( strText );
	strText = strText == "关　闭" ? "开　启" : "关　闭" ;
	m_btnSetting.SetWindowText( strText );
}

void CVideoChatDlg::OnSelf() 
{
	CString strText;
	m_btnSelf.GetWindowText( strText );

	CRect rect;
	GetWindowRect( &rect );
	CRect rectFriend;
	m_staticFriend.GetWindowRect( &rectFriend );
	CRect rectSelf;
	m_staticSelf.GetWindowRect( &rectSelf );

	int nSpace = rectSelf.left - rectFriend.right;

	/// 收缩
	if( strText == "<<<" )
	{
		strText = ">>>";
		m_btnSelf.SetWindowText( strText );
		SetWindowPos( NULL, 0, 0, rect.Width() - rectSelf.Width() - nSpace, rect.Height(), SWP_NOMOVE | SWP_NOZORDER );
	}
	else
	{
		strText = "<<<";
		m_btnSelf.SetWindowText( strText );
		SetWindowPos( NULL, 0, 0, rect.Width() + rectSelf.Width() + nSpace, rect.Height(), SWP_NOMOVE | SWP_NOZORDER );
	}
}

/// 用户断开了视频连接
void CVideoChatDlg::Disconnect()
{
	m_bDeny = TRUE;
	SetConnect( FALSE );

	/// 在内存dc上写字
	CRect rectFriend;
	m_staticFriend.GetClientRect( &rectFriend );
	m_dcMem.SetTextColor( RGB( 255, 0, 0 ) );
	m_dcMem.SetBkMode( TRANSPARENT );
	CString strText( "对方断开了视频连接" );
	m_dcMem.DrawText( strText, rectFriend, DT_CENTER | DT_VCENTER | DT_SINGLELINE );

	/// 隐藏聊天对象的视频窗口
	m_staticFriend.ShowWindow( SW_HIDE );
}


void CVideoChatDlg::OnMike()
{
	m_bRecord = m_btnMike.GetCheck();
}

void CVideoChatDlg::OnTrump()
{
	m_bReceiveAudio = m_btnTrump.GetCheck();

	/// 播放音频数据
	if( m_bReceiveAudio )
	{
		/// 播放追上接收
		if( m_nReceive == m_nPlay )
		{
			m_bPlaying = FALSE;
			return;
		}
		m_bPlaying				= TRUE;
		char *pPlayData			= m_arrAudioBuffer.GetAt( m_nPlay );
		memcpy( &m_dwRecordAudioTickTime, ( BYTE * )pPlayData, sizeof( DWORD ) );
		m_dwPlayAudioTickTime	= ::GetTickCount();
		m_pWaveHdr1->lpData		= pPlayData + sizeof( DWORD );
		waveOutPrepareHeader( m_hWaveOut, m_pWaveHdr1, sizeof( WAVEHDR ) );
		waveOutWrite( m_hWaveOut, m_pWaveHdr1, sizeof( WAVEHDR ) ) ;
		m_nPlay = ( m_nPlay + 1 ) % AUDIO_BUFFER_BLOCK;
	}
	else
	{
		m_bPlaying = FALSE;
	}
}

void CVideoChatDlg::WaveOutOpen( WPARAM wParam, LPARAM lParam )
{
	return;
}

void CVideoChatDlg::WaveOutDone( WPARAM wParam, LPARAM lParam )
{
	if( m_bReceiveAudio )
	{
		/// 播放追上接收
		if( m_nReceive == m_nPlay )
		{
			m_bPlaying = FALSE;
			return;
		}
		m_bPlaying				= TRUE;
		char *pPlayData			= m_arrAudioBuffer.GetAt( m_nPlay );
		memcpy( &m_dwRecordAudioTickTime, ( BYTE * )pPlayData, sizeof( DWORD ) );
		m_dwPlayAudioTickTime	= ::GetTickCount();
		m_pWaveHdr1->lpData		= pPlayData + sizeof( DWORD );
		waveOutPrepareHeader( m_hWaveOut, m_pWaveHdr1, sizeof( WAVEHDR ) );
		waveOutWrite( m_hWaveOut, m_pWaveHdr1, sizeof( WAVEHDR ) ) ;
		m_nPlay = ( m_nPlay + 1 ) % AUDIO_BUFFER_BLOCK;
	}
	return;
}

void CVideoChatDlg::WaveOutClose( WPARAM wParam, LPARAM lParam )
{
	return;
}

/// 拒绝视频
void CVideoChatDlg::DenyVideoChat()
{
	m_bDeny = TRUE;
	
	/// 在内存dc上写字
	CRect rectFriend;
	m_staticFriend.GetClientRect( &rectFriend );
	m_dcMem.SetTextColor( RGB( 255, 0, 0 ) );
	m_dcMem.SetBkMode( TRANSPARENT );
	CString strText( "拒绝视频聊天" );
	m_dcMem.DrawText( strText, rectFriend, DT_CENTER | DT_VCENTER | DT_SINGLELINE );

	/// 隐藏聊天对象的视频窗口
	m_staticFriend.ShowWindow( SW_HIDE );
}

void CVideoChatDlg::OnPaint() 
{
	CPaintDC dc(this);
	
	if( m_bDeny )
	{
		CRect rectFriend;
		m_staticFriend.GetWindowRect( &rectFriend );
		ScreenToClient( rectFriend );
		dc.BitBlt( rectFriend.left, rectFriend.top, rectFriend.Width(), rectFriend.Height(),
			&m_dcMem, 0, 0, SRCCOPY );
	}
}

/// 更新自己的视频画面
void CVideoChatDlg::SetSelfPicture( const BITMAPINFO bmpInfo, 
									unsigned char *pData, 
									DWORD dwBufferSize )
{
	BYTE *pRGBData = new BYTE[ bmpInfo.bmiHeader.biSizeImage ];
	YUY2_RGB( pData, pRGBData, bmpInfo.bmiHeader.biSizeImage * 4 / 6 );

	CDC *pDC = m_staticSelf.GetDC();
	CRect rectSelf;
	m_staticSelf.GetClientRect( &rectSelf );
	rectSelf.DeflateRect( 2, 2 );
	
	HBITMAP hBitmap = ::CreateDIBitmap( pDC->m_hDC, &( bmpInfo.bmiHeader ), CBM_INIT, pRGBData,
		&bmpInfo, DIB_RGB_COLORS );

	delete [] pRGBData;

	HDC dcMem = ::CreateCompatibleDC( pDC->m_hDC );
	::SelectObject( dcMem, hBitmap );

	CString strText;
	m_btnSetting.GetWindowText( strText );
	if( strText == "关　闭" )
	{
		/// 得到视频画面的宽与长
		int nPictureWidth	= bmpInfo.bmiHeader.biWidth;
		int nPictureHeight	= -bmpInfo.bmiHeader.biHeight;

		/// 定义视频画面的源点与长宽
		int nX, nY, nWidth, nHeight;

		/// 自己视频窗口能容得下视频画面
		if( nPictureHeight < rectSelf.Height() && nPictureWidth < rectSelf.Width() )
		{
			nX		= rectSelf.left + ( rectSelf.Width() - nPictureWidth ) / 2;
			nY		= rectSelf.top + ( rectSelf.Height() - nPictureHeight ) / 2;
			nWidth	= nPictureWidth;
			nHeight	= nPictureHeight;
		}

		/// 视频窗口的高有空余
		else if( ( float )rectSelf.Height() / rectSelf.Width() > ( float )nPictureHeight / nPictureWidth )
		{
			nX		= rectSelf.left;
			nWidth	= rectSelf.Width();
			nHeight	= nWidth * nPictureHeight / nPictureWidth;
			nY		= rectSelf.top + ( rectSelf.Height() - nHeight ) / 2;
		}

		/// 视频窗口的长有空余或比例一样
		else
		{
			nY		= rectSelf.top;
			nHeight	= rectSelf.Height();
			nWidth	= nHeight * nPictureWidth / nPictureHeight;
			nX		= rectSelf.left + ( rectSelf.Width() - nWidth ) / 2;
		}

		::StretchBlt( pDC->m_hDC, 
			nX, nY, nWidth, nHeight,
			dcMem,
			0, 0, bmpInfo.bmiHeader.biWidth, -bmpInfo.bmiHeader.biHeight,
			SRCCOPY );
	}
	else
	{
		pDC->FillSolidRect( rectSelf, RGB( 128, 128, 128 ) );
	}
	
	::DeleteObject( hBitmap );
	::DeleteObject( dcMem );
	ReleaseDC( pDC );
}

/// 更新好友的视频窗口画面
void CVideoChatDlg::UpdateFriendVideoPicture( BYTE *pVideoReceiveData, DWORD dwDataLength )
{
	CDebug debug( "UpdateFriendVideoPicture" );

	CString strVideoData( ( LPCTSTR )pVideoReceiveData, dwDataLength );
	m_lstVideoData.AddTail( strVideoData );

	CString strData;
	BITMAPINFO bmpInfo;
	BYTE *pRGBData;


	/// 如果没有播放音频，则直接贴图
	if( !m_bPlaying )
	{
		strData = m_lstVideoData.GetHead();
		m_lstVideoData.RemoveHead();
		BYTE *pVideoData = ( BYTE * )strData.GetBuffer( strData.GetLength() );
		memcpy( &bmpInfo, pVideoData + sizeof( DWORD ), sizeof( BITMAPINFO ) );
		pRGBData = new BYTE[ bmpInfo.bmiHeader.biSizeImage ];
		YUY2_RGB( pVideoData + sizeof( DWORD ) + sizeof( BITMAPINFO ), 
				pRGBData, 
				bmpInfo.bmiHeader.biSizeImage * 4 / 6 );
		strData.ReleaseBuffer( -1 );
	}
	
	/// 正在播放音频，需要对视频数据进行处理
	else
	{
		DWORD dwStandardVideoTime = ::GetTickCount() - m_dwPlayAudioTickTime + m_dwRecordAudioTickTime;
		
		DWORD dwVideoTime;
		BOOL bSmallerThanStandardVideoTime	= FALSE;

		/// 循环判断每个视频时间与标准播放时间的距离
		int nVideoDataCount = m_lstVideoData.GetCount();
		for( int nIndex = 0; nIndex < nVideoDataCount; nIndex++ )
		{
			strData = m_lstVideoData.GetHead();
			BYTE *pVideoData = ( BYTE * )strData.GetBuffer( strData.GetLength() );
			memcpy( &dwVideoTime, pVideoData, sizeof( DWORD ) );
			
			/// 如果视频时间与标准时间相等或大于但已经过了一个小于的
			if( ( dwVideoTime > dwStandardVideoTime && bSmallerThanStandardVideoTime ) ||
				dwVideoTime == dwStandardVideoTime )
			{
				m_lstVideoData.RemoveHead();
				memcpy( &bmpInfo, pVideoData + sizeof( DWORD ), sizeof( BITMAPINFO ) );
				pRGBData = new BYTE[ bmpInfo.bmiHeader.biSizeImage ];
				YUY2_RGB( pVideoData + sizeof( DWORD ) + sizeof( BITMAPINFO ), 
						pRGBData, 
						bmpInfo.bmiHeader.biSizeImage * 4 / 6 );
				strData.ReleaseBuffer( -1 );
				break;
			}

			/// 如果视频时间小于标准时间，丢弃视频数据
			else if( dwVideoTime < dwStandardVideoTime )
			{
				bSmallerThanStandardVideoTime = TRUE;
				m_lstVideoData.RemoveHead();
				strData.ReleaseBuffer( -1 );
				continue;
			}

			/// 如果视频时间大于标准时间，则不作处理，直接返回
			else if( dwVideoTime > dwStandardVideoTime )
			{
				strData.ReleaseBuffer( -1 );
				return;
			}
		}
	}

	CDC *pDC = m_staticFriend.GetDC();
	CRect rectFriend;
	m_staticFriend.GetClientRect( &rectFriend );
	rectFriend.DeflateRect( 2, 2 );
	
	HBITMAP hBitmap = ::CreateDIBitmap( pDC->m_hDC, &( bmpInfo.bmiHeader ), CBM_INIT, 
		pRGBData,
		&bmpInfo, DIB_RGB_COLORS );

	delete [] pRGBData;
	pRGBData = NULL;

	HDC dcMem = ::CreateCompatibleDC( pDC->m_hDC );
	::SelectObject( dcMem, hBitmap );
	
	/// 得到视频画面的宽与长
	int nPictureWidth	= bmpInfo.bmiHeader.biWidth;
	int nPictureHeight	= -bmpInfo.bmiHeader.biHeight;
	
	/// 定义视频画面的源点与长宽
	int nX, nY, nWidth, nHeight;
	
	/// 自己视频窗口能容得下视频画面
	if( nPictureHeight < rectFriend.Height() && nPictureWidth < rectFriend.Width() )
	{
		nX		= rectFriend.left + ( rectFriend.Width() - nPictureWidth ) / 2;
		nY		= rectFriend.top + ( rectFriend.Height() - nPictureHeight ) / 2;
		nWidth	= nPictureWidth;
		nHeight	= nPictureHeight;
	}
	
	/// 视频窗口的高有空余
	else if( ( float )rectFriend.Height() / rectFriend.Width() > ( float )nPictureHeight / nPictureWidth )
	{
		nX		= rectFriend.left;
		nWidth	= rectFriend.Width();
		nHeight	= nWidth * nPictureHeight / nPictureWidth;
		nY		= rectFriend.top + ( rectFriend.Height() - nHeight ) / 2;
	}
	
	/// 视频窗口的长有空余或比例一样
	else
	{
		nY		= rectFriend.top;
		nHeight	= rectFriend.Height();
		nWidth	= nHeight * nPictureWidth / nPictureHeight;
		nX		= rectFriend.left + ( rectFriend.Width() - nWidth ) / 2;
	}
	
	::StretchBlt( pDC->m_hDC, 
		nX, nY, nWidth, nHeight,
		dcMem,
		0, 0, bmpInfo.bmiHeader.biWidth, -bmpInfo.bmiHeader.biHeight,
		SRCCOPY );

	::DeleteObject( hBitmap );
	::DeleteObject( dcMem );
	ReleaseDC( pDC );
}

/// 接收到音频数据，保存起来
void CVideoChatDlg::SaveAudioData( char *pData, DWORD dwDataLength )
{
	CDebug debug( "SaveAudioData" );

	/// 保存接收到的音频数据
	char *pSaveData = m_arrAudioBuffer.GetAt( m_nReceive );
	memcpy( pSaveData, pData, dwDataLength );

	/// 新的接收区块号
	m_nReceive = ( m_nReceive + 1 ) % AUDIO_BUFFER_BLOCK;

	/// 接收追上播放，播放往前走
	if( m_nReceive == m_nPlay )
	{
		m_nPlay = ( m_nPlay + 1 ) % AUDIO_BUFFER_BLOCK;
	}
	if( !m_bPlaying && m_bReceiveAudio )
	{
		m_bPlaying				= TRUE;
		char *pPlayData			= m_arrAudioBuffer.GetAt( m_nPlay );
		memcpy( &m_dwRecordAudioTickTime, ( BYTE * )pPlayData, sizeof( DWORD ) );
		m_dwPlayAudioTickTime	= ::GetTickCount();
		m_pWaveHdr1->lpData		= pPlayData + sizeof( DWORD );
		waveOutPrepareHeader( m_hWaveOut, m_pWaveHdr1, sizeof( WAVEHDR ) );
		waveOutWrite( m_hWaveOut, m_pWaveHdr1, sizeof( WAVEHDR ) ) ;
		m_nPlay = ( m_nPlay + 1 ) % AUDIO_BUFFER_BLOCK;
	}
}

/// 接收视频和音频数据
void CVideoChatDlg::OnReceive()
{
	BYTE pTempData[ sizeof( DATAPACKET ) ];
	BYTE *pReceiveData;
	BYTE *pTempReceive;
	DWORD dwReceiveLength	= 0;
	DWORD dwReceiveCount	= 0;
	DWORD dwDataLength		= 0;
	DATAPACKET dataPacket;
	
	/// 循环接收数据
	do
	{
		if( 0 == dwReceiveCount )
		{
			dwReceiveLength = m_VideoChatSocket.Receive( pTempData, sizeof( DATAPACKET ) );
			dwReceiveCount	+= dwReceiveLength;
			memcpy( &dataPacket, pTempData, sizeof( DATAPACKET ) );
			dwDataLength	= dataPacket.dwLength - sizeof( DATAPACKET );
			pReceiveData	= new BYTE[ dwDataLength ];
			pTempReceive	= pReceiveData;
		}
		else
		{
			dwReceiveLength = m_VideoChatSocket.Receive( pTempReceive, dwDataLength );
			dwReceiveCount	+= dwReceiveLength;
			dwDataLength	-= dwReceiveLength;
			pTempReceive	+= dwReceiveLength;
		}
	}while( dwReceiveCount < dataPacket.dwLength );

	/// 根据命令进行不同的处理
	switch( dataPacket.command )
	{
	case VIDEOCHAT_VIDEO_PICTURE:								/// 视频画面数据
		UpdateFriendVideoPicture( pReceiveData, dataPacket.dwLength - sizeof( DATAPACKET ) );
		SendCommand( VIDEOCHAT_VIDEO_RECEIVE_FINISHED );
		break;
	case VIDEOCHAT_AUDIO_DATA:									/// 音频数据
		SaveAudioData( ( char * )pReceiveData, dataPacket.dwLength - sizeof( DATAPACKET ) );
		SendCommand( VIDEOCHAT_VIDEO_RECEIVE_FINISHED );
		break;
	case VIDEOCHAT_VIDEO_RECEIVE_FINISHED:						/// 视频数据接收完毕
		ReceiveFinished();
		break;
	default:
		break;
	}

	delete [] pReceiveData;
}


/// 更新自己的画面并发送数据
void CVideoChatDlg::UpdateVideoPicture( DWORD dwTickCount,
									   const BITMAPINFO bmpInfo, 
									   unsigned char *pData, 
									   DWORD dwBufferSize )
{
	/// 更新自己的画面
	SetSelfPicture( bmpInfo, pData, dwBufferSize );

	/// 如果连接上
	if( m_bConnect && m_bReceiveFinished )
	{
		CDebug debug( "SendVideoPicture" );

		/// 设置接收完毕标志为FALSE
		m_bReceiveFinished = FALSE;

		/// 将更新的视频数据保存起来
		DWORD dwDataSize = sizeof( DATAPACKET ) + sizeof( DWORD ) + sizeof( BITMAPINFO ) + dwBufferSize;

		BYTE *pVideoSendData = new BYTE[ dwDataSize ];
	
		/// 数据包
		DATAPACKET dataPacket;
		dataPacket.command		= VIDEOCHAT_VIDEO_PICTURE;
		dataPacket.dwLength		= dwDataSize;

		memcpy( pVideoSendData, &dataPacket, sizeof( DATAPACKET ) );
		memcpy( pVideoSendData + sizeof( DATAPACKET ), &dwTickCount, sizeof( DWORD ) );
		memcpy( pVideoSendData + sizeof( DATAPACKET ) + sizeof( DWORD ), &bmpInfo, sizeof( BITMAPINFO ) );
		memcpy( pVideoSendData + sizeof( DATAPACKET ) + sizeof( DWORD ) + sizeof( BITMAPINFO ),
			pData,
			dwBufferSize );
		
		/// 循环发送数据
		BYTE *pSendData			= pVideoSendData;
		DWORD dwSendDataLength	= dwDataSize;
		DWORD dwCountSendLength	= 0;
		int nSendLength			= 0;
		do
		{
			nSendLength			= m_VideoChatSocket.Send( pSendData, dwSendDataLength );
			dwCountSendLength	+= nSendLength;
			dwSendDataLength	-= nSendLength;
			pSendData			+= nSendLength;
		}while( dwCountSendLength < dwDataSize );
		
		delete [] pVideoSendData;
	}
}

/// 发送声音数据
void CVideoChatDlg::SendAudioData( DWORD dwTickCount, char *pAudioData, DWORD dwBufferSize )
{
	/// 如果视频已连接上而且允许对方接收音频
	if( m_bConnect && m_bRecord )
	{	
		/// 将发送音频数据的大小
		DWORD dwDataSize = sizeof( DATAPACKET ) + sizeof( DWORD ) + dwBufferSize;
		
		BYTE *pVideoSendData = new BYTE[ dwDataSize ];
		
		/// 数据包
		DATAPACKET dataPacket;
		dataPacket.command		= VIDEOCHAT_AUDIO_DATA;
		dataPacket.dwLength		= dwDataSize;
		
		memcpy( pVideoSendData, &dataPacket, sizeof( DATAPACKET ) );
		memcpy( pVideoSendData + sizeof( DATAPACKET ), &dwTickCount, sizeof( DWORD ) );
		memcpy( pVideoSendData + sizeof( DATAPACKET ) + sizeof( DWORD ), pAudioData, dwBufferSize );
		
		/// 如果视频数据发送完毕，则可以发送音频数据
		if( m_bReceiveFinished )
		{
			CDebug debug( "SendAudioData" );

			/// 设置接收完毕标志为FALSE
			m_bReceiveFinished		= FALSE;

			/// 循环发送数据
			BYTE *pSendData			= pVideoSendData;
			DWORD dwSendDataLength	= dwDataSize;
			DWORD dwCountSendLength	= 0;
			int nSendLength			= 0;
			do
			{
				nSendLength			= m_VideoChatSocket.Send( pSendData, dwSendDataLength );
				dwCountSendLength	+= nSendLength;
				dwSendDataLength	-= nSendLength;
				pSendData			+= nSendLength;
			}while( dwCountSendLength < dwDataSize );
		}

		/// 如果正在发送视频数据，则把音频保存起来 
		else
		{
			m_dwAudioDataSize = dwDataSize;
			if( !m_pAudioData )
			{
				m_pAudioData = new BYTE[ m_dwAudioDataSize ];
				memcpy( m_pAudioData, pVideoSendData, m_dwAudioDataSize );
			}
		}

		delete [] pVideoSendData;		
	}
}

///	连接到服务器
void CVideoChatDlg::ConnectToServer()
{
	CDebug debug( "ConnectToServer" );
	
	/// 设置连接上的标志
	SetConnect( TRUE );
	
	/// 创建socket，并向服务器发起连接
	m_VideoChatSocket.SetVideoChatDlg( this );
	m_VideoChatSocket.Create();
	m_VideoChatSocket.Connect( m_userChat.strIP, VIDEOCHAT_PORT );
}

/// 附加客户端的socket
void CVideoChatDlg::AttachClientSocket( SOCKET hSocket, CVideoChatDlg *pVidelChatDlg )
{
	CDebug debug( "AttachClientSocket" );
	
	m_VideoChatSocket.Attach( hSocket );
	m_VideoChatSocket.SetVideoChatDlg( pVidelChatDlg );
}

// 发送消息
void CVideoChatDlg::SendCommand( CONTROLCOMMAND command )
{
	DATAPACKET dataPacket;
	dataPacket.command		= command;
	dataPacket.dwLength		= sizeof( DATAPACKET );

	UINT uSendDataLength	= sizeof( DATAPACKET );
	BYTE *pSendData			= new BYTE[ uSendDataLength ];
	memcpy( pSendData, &dataPacket, sizeof( DATAPACKET ) );
	m_VideoChatSocket.Send( pSendData, uSendDataLength );
}

/// 接收完毕
void CVideoChatDlg::ReceiveFinished()
{
	CDebug debug( "ReceiveFinished" );

	/// 如果保存音频的缓冲区为空，则没有需要发送的数据
	if( !m_pAudioData )
	{
		m_bReceiveFinished = TRUE;
		return;
	}

	CDebug debug1( "SendAudioData" );

	/// 设置接收完毕标志为FALSE
	m_bReceiveFinished		= FALSE;
	
	/// 循环发送保存的音频数据
	BYTE *pSendData			= m_pAudioData;
	DWORD dwSendDataLength	= m_dwAudioDataSize;
	DWORD dwCountSendLength	= 0;
	int nSendLength			= 0;
	do
	{
		nSendLength			= m_VideoChatSocket.Send( pSendData, dwSendDataLength );
		dwCountSendLength	+= nSendLength;
		dwSendDataLength	-= nSendLength;
		pSendData			+= nSendLength;
	}while( dwCountSendLength < m_dwAudioDataSize );

	/// 发送完毕，将缓冲区删除
	delete [] m_pAudioData;
	m_pAudioData = NULL;
}

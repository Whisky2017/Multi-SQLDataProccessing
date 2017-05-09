package com.test.action;

import com.opensymphony.xwork2.Action;
import com.opensymphony.xwork2.ActionSupport;
import com.test.pojo.Fuheplan;
import com.test.pojo2.Fuheplan2;
import com.test.service.FuheplanService;
import com.test.util.Util;
import org.springframework.beans.factory.annotation.Autowired;

import java.sql.Timestamp;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * Created by 世康 on 2016/9/19.
 */
public class FuheplanAction extends ActionSupport {

    private static final long serialVersionUID = 1L;

    @Autowired
    private FuheplanService fuheplanService;

    @Autowired
    private com.test.service2.FuheplanService fuheplan2Service;

    private List<Fuheplan> list;

    private List<Fuheplan2> list2;

    private int currentPage = 1;
    private int totalPage;
    private int totalSize;
    private int pageSize = Util.PAGE_SIZE;
    private Map<String, String> errorsMap = new HashMap<String, String>();

    private String id;
    private int planId;
    private String planValue;
    private Timestamp planTime;
    private int planSortId;

    public int getCurrentPage(){return currentPage;}

    public void setCurrentPage(int currentPage) {
        this.currentPage = currentPage;
    }

    public int getTotalPage() {
        return totalPage;
    }

    public void setTotalPage(int totalPage) {
        this.totalPage = totalPage;
    }

    public int getTotalSize() {
        return totalSize;
    }

    public void setTotalSize(int totalSize) {
        this.totalSize = totalSize;
    }

    public int getPageSize() {
        return pageSize;
    }

    public void setPageSize(int pageSize) {
        this.pageSize = pageSize;
    }

    public Map<String, String> getErrorsMap() {
        return errorsMap;
    }

    public void setErrorsMap(Map<String, String> errorsMap) {
        this.errorsMap = errorsMap;
    }

    public List<Fuheplan> getList() {
        return list;
    }

    public void setList(List<Fuheplan> list) {
        this.list = list;
    }

    public String getId() {
        return id;
    }

    public void setId(String id) {
        this.id = id;
    }

    public int getPlanId() {
        return planId;
    }

    public void setPlanId(int planId) {
        this.planId = planId;
    }

    public String getPlanValue() {
        return planValue;
    }

    public void setPlanValue(String planValue) {
        this.planValue = planValue;
    }

    public int getPlanSortId() {
        return planSortId;
    }

    public void setPlanSortId(int planSortId) {
        this.planSortId = planSortId;
    }

    public Timestamp getPlanTime() {
        return planTime;
    }

    public void setPlanTime(Timestamp planTime) {
        this.planTime = planTime;
    }

    public String queryById(){
        Fuheplan fuheplan = fuheplanService.getFuheplanById(id);
        if(fuheplan == null){
            errorsMap.put(Util.MSG_ERRORINFO,"该数据不存在！");
            return Action.ERROR;
        }
        planId = fuheplan.getPlanId();
        planValue = fuheplan.getPlanValue();
        planTime = fuheplan.getPlanTime();
        planSortId = fuheplan.getPlanSortId();

        return Action.SUCCESS;
    }

    public String queryAll(){
//        totalSize = 0;
//        pageSize = Util.PAGE_SIZE;
        list = fuheplanService.getFuheplanAll();
//        totalSize = fuheplanService.getFuheplanCount();
//        if (totalSize % pageSize == 0) {
//            totalPage = totalSize / pageSize;
//        } else {
//            totalPage = (totalSize / pageSize) + 1;
//        }
//        System.out.println("11111");
//        System.out.println(list);
        return Action.SUCCESS;
    }

    public String queryAll2(){
//        totalSize = 0;
//        pageSize = Util.PAGE_SIZE;
        list = fuheplanService.getFuheplanAll();
        list2 = fuheplan2Service.getFuheplanAll();

        for(int i =0;i<list2.size();i++){
            Fuheplan fuheplan1 = list.get(i);
            Fuheplan2 fuheplan2 = list2.get(i);


            if (fuheplan1.getPlanValue().equals(fuheplan2.getPlanValue2()))
                System.out.println("true");
//            System.out.println("vaule1="+fuheplan1.getPlanValue()+",value2="+fuheplan2.getPlanValue2());
            if ((fuheplan1.getPlanId()==fuheplan2.getPlanId2())&&(fuheplan1.getPlanValue().equals(fuheplan2.getPlanValue2())))
                System.out.println("true2");
                list.remove(fuheplan1);
        }

//        System.out.println(list.size());
//        totalSize = fuheplanService.getFuheplanCount();
//        if (totalSize % pageSize == 0) {
//            totalPage = totalSize / pageSize;
//        } else {
//            totalPage = (totalSize / pageSize) + 1;
//        }
//        System.out.println("11111");
        return Action.SUCCESS;
    }
}
